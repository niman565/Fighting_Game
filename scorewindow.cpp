#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>

void ScoreWindow::loadScores()
{
  std::ifstream ifsScores("scores.txt");
  int tempScore;
  for(int i = 0; i < numberOfScores; i++)
  {
    ifsScores >> tempScore;
    scores[i] = tempScore;
    scoreOutput[i]->value(tempScore);
  }
  ifsScores.close();

  std::ifstream ifsNames("names.txt");
  std::string tempName;
  for(int i = 0; i < numberOfScores; i++)
  {
    ifsNames >> tempName;
    names[i] = tempName;
    nameOutput[i]->value((const char*) tempName.c_str());
  }
  ifsNames.close();
}

void ScoreWindow::sortScores()
{
  int tempScore;
  std::string tempName;
  for(int i = 0; i < (numberOfScores ); i++)
  {
      for(int j = 0; j < numberOfScores; j++)
      {
            if(scores[i]>scores[j])
            {
                 tempScore = scores[i];
                 scores[i] = scores[j];
                 scores[j] = tempScore;

                 tempName = names[i];
                 names[i] = names[j];
                 names[j] = tempName;
            }
            scoreOutput[i]->value(scores[i]);
            scoreOutput[j]->value(scores[j]);
            nameOutput[i]->value((const char*) names[i].c_str());
            nameOutput[j]->value((const char*) names[j].c_str());
       }
  }
  redraw();
}

int ScoreWindow::insertScore() {
    for (int i = 0; i < numberOfScores; i++) {
        if (userScore >= scores[i]) {
            for (int j = numberOfScores - 1; j > i; j--) {
                scores[j] = scores[j-1];
                names[j] = names[j-1];
            }
            scores[i] = userScore;
            names[i] = userName;
            return 1;
        }
    }
    return 0;
}

void ScoreWindow::saveScores()
{
  std::ofstream ofsScores("scores.txt");
  for(int i = 0; i < numberOfScores; i++)
    ofsScores << scores[i] << std::endl;
  ofsScores.close();

  std::ofstream ofsNames("names.txt");
  for(int i = 0; i < numberOfScores; i++)
    ofsNames << names[i] << std::endl;
  ofsNames.close();
}

void ScoreWindow::backButtonPress() {
    saveScores();
    this->hide();
    startWindow->startup();
}

void ScoreWindow::submitButtonPress() {
    userName = enterName->value();
    insertScore();
    sortScores();
    submitButton->deactivate();
}

void ScoreWindow::startup(int userScore) {
    this->show();
    backgroundBox->image(backgroundImage);
    this->userScore = userScore;
    scoreBox->value(userScore);
    submitButton->activate();
    loadScores();
    sortScores();
}
