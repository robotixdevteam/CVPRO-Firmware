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
    left_front(ctrl_left, 0);
    left_back(ctrl_left, 0);
    right_front(0, -ctrl_right);
    right_back(0, -ctrl_right);
  }

  // left
  if ((ctrl_left < 0) && (ctrl_right > 0)) {
    left_front(0, -ctrl_left);
    left_back(0, -ctrl_left);
    right_front(ctrl_right, 0);
    right_back(ctrl_right, 0);
  }

  // backward
  if ((ctrl_left < 0) && (ctrl_right < 0)) {
    left_front(0, -ctrl_left);
    left_back(0, -ctrl_left);
    right_front(0, -ctrl_right);
    right_back(0, -ctrl_right);
  }
}