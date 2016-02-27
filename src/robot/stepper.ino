
int stepper_step;
int stepper_dir;
int stepper_current_direction;


void stepper_step_motor() {
  digitalWrite(pin_step, LOW);
  digitalWrite(pin_step, HIGH);
}

void stepper_move_forward() {
  digitalWrite(pin_dir, LOW);
  step_motor();
}

void stepper_move_backward() {
  digitalWrite(pin_dir, HIGH);
  step_motor();
}

void stepper_move(int dir) {
  if(dir == 1) {
    stepper_move_forward();
  else {
    stepper_move_backward();
  }
}
