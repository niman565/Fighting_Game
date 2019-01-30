#include <iostream>
#include <sstream>
#include <cstdlib>

void StartWindow::startButtonPress() {
    this->hide();
    fighterSelectionWindow->startup();
}

void StartWindow::howButtonPress() {
    this->hide();
    infoWindow->startup();
}

void StartWindow::quitButtonPress() {
    std::exit(0);
}

void StartWindow::startup() {
    this->show();
    backgroundBox->image(backgroundImage);
}
