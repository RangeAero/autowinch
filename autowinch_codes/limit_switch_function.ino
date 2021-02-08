void setup_Limit_switch(){
  pinMode(limit_switch_pin_left, INPUT_PULLUP); 
  pinMode(limit_switch_pin_right, INPUT_PULLUP);
  //digitalWrite(limit_switch_pin_left, HIGH); //turn pullup resistor on
  //digitalWrite(limit_switch_pin_right, HIGH); //turn pullup resistor on
  attachInterrupt(digitalPinToInterrupt(limit_switch_pin_left), change_dir, FALLING); 
  attachInterrupt(digitalPinToInterrupt(limit_switch_pin_right), change_dir, FALLING);

  
  }

void change_dir(){
  dir_flag *= -1;
  }  
