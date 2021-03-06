// generated by Fast Light User Interface Designer (fluid) version 1.0110

#ifndef fight_h
#define fight_h
#include <FL/Fl.H>
#include <FL/Fl_GIF_Image.H>
#include <string>
class Fighter;
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

class BackgroundSelectionWindow : public Fl_Double_Window {
  void _BackgroundSelectionWindow();
public:
  BackgroundSelectionWindow(int X, int Y, int W, int H, const char *L = 0);
  BackgroundSelectionWindow(int W, int H, const char *L = 0);
private:
  int handle(int event); 
  int getSelectedOption(); 
  void selectButtonPress(); 
public:
  void startup(); 
  Fl_Box *options[6];
  Fl_Box *selectBox;
  Fl_Button *selectButton;
private:
  void cb_selectButton_i(Fl_Button*, void*);
  static void cb_selectButton(Fl_Button*, void*);
};

class StartWindow : public Fl_Double_Window {
  void _StartWindow();
public:
  StartWindow(int X, int Y, int W, int H, const char *L = 0);
  StartWindow(int W, int H, const char *L = 0);
private:
  void startButtonPress(); 
  void howButtonPress(); 
  void quitButtonPress(); 
public:
  void startup(); 
  Fl_Box *backgroundBox;
  Fl_Button *startButton;
private:
  void cb_startButton_i(Fl_Button*, void*);
  static void cb_startButton(Fl_Button*, void*);
public:
  Fl_Button *howButton;
private:
  void cb_howButton_i(Fl_Button*, void*);
  static void cb_howButton(Fl_Button*, void*);
public:
  Fl_Button *quitButton;
private:
  void cb_quitButton_i(Fl_Button*, void*);
  static void cb_quitButton(Fl_Button*, void*);
};
#include <FL/Fl_Text_Display.H>

class InfoWindow : public Fl_Double_Window {
  void _InfoWindow();
public:
  InfoWindow(int X, int Y, int W, int H, const char *L = 0);
  InfoWindow(int W, int H, const char *L = 0);
private:
  void backButtonPress(); 
public:
  void startup(); 
  Fl_Box *backgroundBox;
  Fl_Text_Display *gameInfoBox;
  Fl_Text_Display *devInfoBox;
  Fl_Button *backButton;
private:
  void cb_backButton_i(Fl_Button*, void*);
  static void cb_backButton(Fl_Button*, void*);
};
#include <FL/Fl_Output.H>

class FighterSelectionWindow : public Fl_Double_Window {
  void _FighterSelectionWindow();
public:
  FighterSelectionWindow(int X, int Y, int W, int H, const char *L = 0);
  FighterSelectionWindow(int W, int H, const char *L = 0);
private:
  Fl_GIF_Image* aggressiveImage; 
  Fl_GIF_Image* balancedImage; 
  Fl_GIF_Image* defensiveImage; 
  void selectButtonPress(); 
public:
  void startup(); 
private:
  int playerStyle; 
public:
  Fl_Box *backgroundBox;
  Fl_Box *fighterBox;
  Fl_Output *instructionBox;
  Fl_Button *aggressiveButton;
private:
  void cb_aggressiveButton_i(Fl_Button*, void*);
  static void cb_aggressiveButton(Fl_Button*, void*);
public:
  Fl_Button *balancedButton;
private:
  void cb_balancedButton_i(Fl_Button*, void*);
  static void cb_balancedButton(Fl_Button*, void*);
public:
  Fl_Button *defensiveButton;
private:
  void cb_defensiveButton_i(Fl_Button*, void*);
  static void cb_defensiveButton(Fl_Button*, void*);
public:
  Fl_Button *selectButton;
private:
  void cb_selectButton1_i(Fl_Button*, void*);
  static void cb_selectButton1(Fl_Button*, void*);
};
#include <FL/Fl_Value_Output.H>

class GameWindow : public Fl_Double_Window {
  void _GameWindow();
public:
  GameWindow(int X, int Y, int W, int H, const char *L = 0);
  GameWindow(int W, int H, const char *L = 0);
private:
  Fighter* player; 
  Fighter* opponent; 
  int score; 
  bool moveIsSelected; 
  int handle(int event); 
public:
  void startup(int playerStyle); 
  int getScore(); 
  Fighter* getPlayer(); 
  Fighter* getOpponent(); 
  bool getMoveIsSelected(); 
  void setMoveIsSelected(bool value); 
  void decrementScore(); 
  Fl_Box *backgroundBox;
  Fl_Box *playerFighterBox;
  Fl_Box *opponentFighterBox;
  Fl_Output *playerNameBox;
  Fl_Output *opponentNameBox;
  Fl_Output *playerStanceBox;
  Fl_Output *opponentStanceBox;
  Fl_Value_Output *playerHealthBox;
  Fl_Value_Output *opponentHealthBox;
  Fl_Value_Output *scoreBox;
};

class EndWindow : public Fl_Double_Window {
  void _EndWindow();
public:
  EndWindow(int X, int Y, int W, int H, const char *L = 0);
  EndWindow(int W, int H, const char *L = 0);
private:
  int score; 
  void highScoresButtonPress(); 
  void mainMenuButtonPress(); 
public:
  void startup(int playerHealth, int gameScore); 
  Fl_Box *backgroundBox;
  Fl_Value_Output *healthBox;
  Fl_Value_Output *scoreBox;
  Fl_Output *messageBox;
  Fl_Button *highScoresButton;
private:
  void cb_highScoresButton_i(Fl_Button*, void*);
  static void cb_highScoresButton(Fl_Button*, void*);
public:
  Fl_Button *mainMenuButton;
private:
  void cb_mainMenuButton_i(Fl_Button*, void*);
  static void cb_mainMenuButton(Fl_Button*, void*);
};
#include <FL/Fl_Input.H>

class ScoreWindow : public Fl_Double_Window {
  void _ScoreWindow();
public:
  ScoreWindow(int X, int Y, int W, int H, const char *L = 0);
  ScoreWindow(int W, int H, const char *L = 0);
  static const int numberOfScores = 5; 
  int userScore; 
  std::string userName; 
  int scores[numberOfScores]; 
  std::string names[numberOfScores]; 
  void startup(int gameScore); 
private:
  void saveScores(); 
  void loadScores(); 
  void sortScores(); 
  int insertScore(); 
  void backButtonPress(); 
  void submitButtonPress(); 
public:
  Fl_Box *backgroundBox;
  Fl_Value_Output *scoreOutput[5];
  Fl_Output *nameOutput[5];
  Fl_Input *enterName;
  Fl_Value_Output *scoreBox;
  Fl_Button *backButton;
private:
  void cb_backButton1_i(Fl_Button*, void*);
  static void cb_backButton1(Fl_Button*, void*);
public:
  Fl_Button *submitButton;
private:
  void cb_submitButton_i(Fl_Button*, void*);
  static void cb_submitButton(Fl_Button*, void*);
};
BackgroundSelectionWindow* makeBackgroundSelectionWindow();
StartWindow* makeStartWindow();
InfoWindow* makeInfoWindow();
FighterSelectionWindow* makeFighterSelectionWindow();
GameWindow* makeGameWindow();
EndWindow* makeEndWindow();
ScoreWindow* makeScoreWindow();
extern BackgroundSelectionWindow* backgroundSelectionWindow;
extern StartWindow* startWindow;
extern InfoWindow* infoWindow;
extern FighterSelectionWindow* fighterSelectionWindow;
extern GameWindow* gameWindow;
extern EndWindow* endWindow;
extern ScoreWindow* scoreWindow;
extern Fl_GIF_Image* backgroundImage;
#endif
