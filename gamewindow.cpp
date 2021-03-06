#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

int GameWindow::handle(int event) {
    int returnCode = Fl_Double_Window::handle(event);
    if (event == FL_FOCUS) {
        returnCode = 1;
    }
    if (event == FL_UNFOCUS) {
        returnCode = 1;
    }
    if (event == FL_KEYDOWN && !moveIsSelected) {
        returnCode = 1;
        if (Fl::event_key(113)) {
            player->setStance(Fighter::BLOCK_HIGH);
            moveIsSelected = true;
        }
        if (Fl::event_key(97)) {
            player->setStance(Fighter::BLOCK_MID);
            moveIsSelected = true;
        }
        if (Fl::event_key(122)) {
            player->setStance(Fighter::BLOCK_LOW);
            moveIsSelected = true;
        }
        if (Fl::event_key(119)) {
            player->setStance(Fighter::ATTACK_HIGH);
            moveIsSelected = true;
        }
        if (Fl::event_key(115)) {
            player->setStance(Fighter::ATTACK_MID);
            moveIsSelected = true;
        }
        if (Fl::event_key(120)) {
            player->setStance(Fighter::ATTACK_LOW);
            moveIsSelected = true;
        }
        playerStanceBox->value((const char*) player->getStanceName().c_str());
        gameWindow->redraw();
    }
    return returnCode;
}

Fighter* GameWindow::getPlayer() {
    return player;
}

Fighter* GameWindow::getOpponent() {
    return opponent;
}

bool GameWindow::getMoveIsSelected() {
    return moveIsSelected;
}

void GameWindow::setMoveIsSelected(bool value) {
    moveIsSelected = value;
}

void GameWindow::decrementScore() {
    score--;
}

void processAction(void*) {
    Fl::focus(gameWindow);
    if (!gameWindow->getMoveIsSelected()) {
        gameWindow->getPlayer()->setStance(Fighter::NEUTRAL);
        gameWindow->playerStanceBox->value((const char*) gameWindow->getPlayer()->getStanceName().c_str());
    gameWindow->redraw();
    }

    srand(time(NULL));
    int attackOrBlockRoll = rand() % 100 + 1;
    int stanceHeightRoll = rand() % 3;
    if (attackOrBlockRoll < gameWindow->getOpponent()->getChanceOfAttack()) {
        switch (stanceHeightRoll) {
            case 0:
                gameWindow->getOpponent()->setStance(Fighter::ATTACK_LOW);
                break;
            case 1:
                gameWindow->getOpponent()->setStance(Fighter::ATTACK_MID);
                break;
            case 2:
                gameWindow->getOpponent()->setStance(Fighter::ATTACK_HIGH);
                break;
        }
    } else {
        switch (stanceHeightRoll) {
            case 0:
                gameWindow->getOpponent()->setStance(Fighter::BLOCK_LOW);
                break;
            case 1:
                gameWindow->getOpponent()->setStance(Fighter::BLOCK_MID);
                break;
            case 2:
                gameWindow->getOpponent()->setStance(Fighter::BLOCK_HIGH);
                break;
        }
    }

    int damageToPlayer = gameWindow->getOpponent()->getPower() - 
      gameWindow->getPlayer()->getToughness();
    if (damageToPlayer < 0) {
        damageToPlayer = 0;
    }
    gameWindow->getPlayer()->adjustHealth(0 - damageToPlayer);

    int damageToOpponent = gameWindow->getPlayer()->getPower() - 
      gameWindow->getOpponent()->getToughness();
    if (damageToOpponent < 0) {
        damageToOpponent = 0;
    }
    gameWindow->getOpponent()->adjustHealth(0 - damageToOpponent);

    gameWindow->decrementScore();

    gameWindow->playerFighterBox->image(gameWindow->getPlayer()->getImage());
     gameWindow->opponentFighterBox->image(gameWindow->getOpponent()->getImage());
    gameWindow->opponentStanceBox->value((const char*) gameWindow->getOpponent()->getStanceName().c_str());
    gameWindow->playerHealthBox->value(gameWindow->getPlayer()->getHealth());
    gameWindow->opponentHealthBox->value(gameWindow->getOpponent()->getHealth());
    gameWindow->scoreBox->value(gameWindow->getScore());

    gameWindow->redraw();
    gameWindow->setMoveIsSelected(false);
    if (gameWindow->getPlayer()->getHealth() > 0 && gameWindow->getOpponent()->getHealth() > 0 && 
      gameWindow->getScore() > 0) {
        Fl::repeat_timeout(1.0, processAction);
    } else {
        endWindow->startup(gameWindow->getPlayer()->getHealth(), gameWindow->getScore());
        gameWindow->hide();
    }
}

void GameWindow::startup(int playerStyle) {
    this->show();
    backgroundBox->image(backgroundImage);

    player = new Fighter(playerStyle);

    srand(time(NULL));
    opponent = new Fighter(rand() % 3 + 3);

    score = 100;

    playerFighterBox->image(player->getImage());
    opponentFighterBox->image(opponent->getImage());
    playerStanceBox->value((const char*) player->getStanceName().c_str());
    opponentStanceBox->value((const char*) opponent->getStanceName().c_str());
    playerNameBox->value((const char*) player->getName().c_str());
    opponentNameBox->value((const char*) opponent->getName().c_str());
    playerHealthBox->value(player->getHealth());
    opponentHealthBox->value(opponent->getHealth());
    scoreBox->value(score);

    moveIsSelected = false;

    Fl::add_timeout(0, processAction);
}

int GameWindow::getScore() {
    return score;
}
