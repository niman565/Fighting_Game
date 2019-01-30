#include <iostream>
#include <sstream>
#include "fight.h"
#include "Fighter.cpp"
#include "backgroundselectionwindow.cpp"
#include "infowindow.cpp"
#include "startwindow.cpp"
#include "fighterselectionwindow.cpp"
#include "gamewindow.cpp"
#include "endwindow.cpp"
#include "scorewindow.cpp"
BackgroundSelectionWindow* backgroundSelectionWindow;
StartWindow* startWindow;
InfoWindow* infoWindow;
FighterSelectionWindow* fighterSelectionWindow;
GameWindow* gameWindow;
EndWindow* endWindow;
ScoreWindow* scoreWindow;

Fl_GIF_Image* backgroundImage;

int main() {
    backgroundSelectionWindow = makeBackgroundSelectionWindow();
    startWindow = makeStartWindow();
    infoWindow = makeInfoWindow();
    fighterSelectionWindow = makeFighterSelectionWindow();
    gameWindow = makeGameWindow();
    endWindow = makeEndWindow();
    scoreWindow = makeScoreWindow();
    backgroundSelectionWindow->show();
    return Fl::run();
}
