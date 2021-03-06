#include <iostream>
#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Text_Display.H>

void InfoWindow::backButtonPress() {
    this->hide();
    startWindow->startup();
}

void InfoWindow::startup() {
    this->show();
    backgroundBox->image(backgroundImage);

    Fl_Text_Buffer *gameInfo = new Fl_Text_Buffer();
    gameInfoBox->buffer(gameInfo);
    gameInfo->text("Moves: \n W -- High Attack \n S -- Mid Attack \n X -- Low Attack \n Q -- High Block \n A -- Mid Block \n Z -- Low Block \n  \n Fighter Types: \n Aggressive -- High attack power, low block toughness \n Balanced -- Moderate attack power, moderate block toughness \n Defensive -- Low attack power, high block toughness \n \n Goal: \n DEFEAT your opponent!!!");

    Fl_Text_Buffer *devInfo = new Fl_Text_Buffer();
    devInfoBox->buffer(devInfo);
    devInfo->text("Programmers: \n Michael Liu \n Henry Sun \n Nihal Manjunath \n Charles Hong");
}
