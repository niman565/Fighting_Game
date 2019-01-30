#include <iostream>
#include <sstream>

void FighterSelectionWindow::selectButtonPress() {
    this->hide();
    gameWindow->startup(playerStyle);
}

void FighterSelectionWindow::startup() {
    this->show();

    aggressiveImage = new Fl_GIF_Image("images/fighters/00.gif");
    balancedImage = new Fl_GIF_Image("images/fighters/10.gif");
    defensiveImage = new Fl_GIF_Image("images/fighters/20.gif");

    backgroundBox->image(backgroundImage);
    instructionBox->value("Select a Fighter:");
    fighterBox->image(balancedImage);
    fighterSelectionWindow->playerStyle = 1;
}
