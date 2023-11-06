//Motor code - All Direction to navigate the motor

void navigation(int ctrl_left, int ctrl_right) {
  // forward
  if ((ctrl_left > 0) && (ctrl_right > 0)) {
    left_front(ctrl_left, 0);
    left_back(ctrl_left, 0);
    right_front(ctrl_right, 0);
    right_back(ctrl_right, 0);
  }

  // stop
  if ((ctrl_left == 0) && (ctrl_right == 0)) {
    left_front(0, 0);
    left_back(0, 0);
    right_front(0, 0);
    right_back(0, 0);
  }

  // right
  if ((ctrl_left > 0) && (ctrl_right < 0)) {
    //cvpro mecanum - Moving sideways right
    if((ctrl_left == 30) && (ctrl_right == -30)){
    //macanum movement speed - 220
    left_front(220, 0);
    left_back(0, 220);
    right_front(0,220);
    right_back(220,0);  
    }
    //cvpro mecanum - Moving diagonally right
    else if((ctrl_left == 15) && (ctrl_right == -15)){
    //macanum movement speed - 220
    left_front(220, 0);
    left_back(0, 0);
    right_front(0,0);
    right_back(220,0);  
    }
    //cvpro mecanum - Moving around blend right
    else if((ctrl_left == 60) && (ctrl_right == -60)){
    left_front(220, 0);
    left_back(220, 0);
    right_front(0,0);
    right_back(0,0); 
    }
    //cvpro mecanum - Rotation right
    else if((ctrl_left == 360) && (ctrl_right == -360)){
    left_front(220, 0);
    left_back(220, 0);
    right_front(0,220);
    right_back(0,220); 
    }
    //cvpro mecanum - Rotation around the central point of one axie in right
    else if((ctrl_left == 120) && (ctrl_right == -120)){
    left_front(220, 0);
    left_back(0, 0);
    right_front(0, 220);
    right_back(0, 0); 
    }
    //cvpro classic right
    else{
    left_front(ctrl_left, 0);
    left_back(ctrl_left, 0);
    right_front(0, -ctrl_right);
    right_back(0, -ctrl_right);
    }
  }

  // left 
  if ((ctrl_left < 0) && (ctrl_right > 0)) {
    //cvpro mecanum - Moving sideways left
     if((ctrl_left == -30) && (ctrl_right == 30)){
      //mecanum movement speed - 220
      left_front(0, 220);
      left_back(220, 0);
      right_front(220,0);
      right_back(0,220);  
      }
    //cvpro mecanum - Moving diagonal left
    else if((ctrl_left == -15) && (ctrl_right == 15)){
    //mecanum movement speed - 220
    left_front(0, 0);
    left_back(220, 0);
    right_front(220,0);
    right_back(0,0);  
    }
    //cvpro mecanum - Moving around blend left
    else if((ctrl_left == -60) && (ctrl_right == 60)){
    left_front(0, 0);
    left_back(0, 0);
    right_front(220,0);
    right_back(220,0); 
    }
    //cvpro mecanum - Rotation left
    else if((ctrl_left == -360) && (ctrl_right == 360)){
    left_front(0, 220);
    left_back(0, 220);
    right_front(220, 0);
    right_back(220, 0); 
    }
    //cvpro mecanum - Rotation around the central point of one axie in left
    else if((ctrl_left == -120) && (ctrl_right == 120)){
    left_front(0, 0);
    left_back(0, 220);
    right_front(0, 0);
    right_back(220, 0); 
    }
    //cvpro classic left
    else{
    left_front(0, -ctrl_left);
    left_back(0, -ctrl_left);
    right_front(ctrl_right, 0);
    right_back(ctrl_right, 0);
  }
  }

  // backward
  if ((ctrl_left < 0) && (ctrl_right < 0)) {
    left_front(0, -ctrl_left);
    left_back(0, -ctrl_left);
    right_front(0, -ctrl_right);
    right_back(0, -ctrl_right);
  }
}