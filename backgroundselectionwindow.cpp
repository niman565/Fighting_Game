
int BackgroundSelectionWindow::handle(int event) {
    static bool selectBoxIsGrabbed = false;
    int returnCode = Fl_Double_Window::handle(event);
    if (event == FL_DRAG) {
        returnCode = 1;
        if (selectBoxIsGrabbed) {
            backgroundSelectionWindow->selectBox->
                  position(Fl::event_x() - selectBox->w()/2,                                         Fl::event_y() - selectBox->h()/2);
            backgroundSelectionWindow->redraw();
        }
    }
    if (event == FL_PUSH) {
        returnCode = 1;
        if (Fl::event_x() > selectBox->x()
         && Fl::event_x() < selectBox->x() + selectBox->w()
         && Fl::event_y() > selectBox->y()
         && Fl::event_y() < selectBox->y() + selectBox->h()) {
            selectBoxIsGrabbed = true;
        }
    }
    if (event == FL_RELEASE) {
        returnCode = 1;
        selectBoxIsGrabbed = false;
    }
    return returnCode;
}

int BackgroundSelectionWindow::getSelectedOption() {
    int x = backgroundSelectionWindow->selectBox->x();
    int y = backgroundSelectionWindow->selectBox->y();
    for (int i = 0; i < 6; i++) {
        if (x > backgroundSelectionWindow->options[i]->x()
                - backgroundSelectionWindow->selectBox->w()
         && x < backgroundSelectionWindow->options[i]->x()
                + backgroundSelectionWindow->options[i]->w()
         && y > backgroundSelectionWindow->options[i]->y()
                - backgroundSelectionWindow->selectBox->h()
         && y < backgroundSelectionWindow->options[i]->y()
                + backgroundSelectionWindow->options[i]->h()) {
            return i;
        }
    }
    return -1;
}

void BackgroundSelectionWindow::selectButtonPress() {
    int option = backgroundSelectionWindow->getSelectedOption();
    if (option != -1) {
        std::ostringstream fileName;
        fileName << "images/backgrounds/" << option << ".gif";
        backgroundImage = new Fl_GIF_Image(fileName.str().c_str());
        this->hide();
        startWindow->startup();
    }
    std::cout << "Background image set to " << option << std::endl;
}
