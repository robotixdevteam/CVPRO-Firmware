// right
void right_motors(){
    left_front(215, 0);
    right_front(0, 215);
    left_back(215, 0);
    right_back(0, 215);
  }

// left
void left_motors(){
    left_front(0, 215);
    right_front(215, 0);
    left_back(0, 215);
    right_back(215, 0);
  }

// forward
void frwd_motors(){
    left_front(215, 0);
    right_front(215, 0);
    left_back(215, 0);
    right_back(215, 0);
  }

// Stop
void platoon_stop(){
    left_front(0, 0);
    right_front(0, 0);
    left_back(0, 0);
    right_back(0, 0);
  }

