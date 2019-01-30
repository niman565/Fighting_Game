#include <iostream>
#include <sstream>
#include <string>

void EndWindow::highScoresButtonPress() {
    this->hide();
    scoreWindow->startup(score);
}

void EndWindow::mainMenuButtonPress() {
    this->hide();
    startWindow->startup();
}

void EndWindow::startup(int playerHealth, int gameScore) {
    this->show();
    backgroundBox->image(backgroundImage);

    highScoresButton->show();
    mainMenuButton->show();
    messageBox->value("Game Over!");
    if (playerHealth <= 0 ) {
        healthBox->value(0);
        highScoresButton->hide();
    } else if (gameScore <= 0) {
        highScoresButton->hide();
    } else {
        healthBox->value(playerHealth);
        mainMenuButton->hide();
    }
    scoreBox->value(gameScore);
    score = gameScore;
}
