void setup_Motor(){
   pinMode(motor_pwm_pin, OUTPUT); 
   pinMode(motor_dir_pin, OUTPUT);
  
  }

void run_motor(int dir, int speed_pwm){
  if (dir == 1)
    digitalWrite(motor_dir_pin, HIGH);
  else if(dir == 0)
    digitalWrite(motor_dir_pin, LOW);
    
  analogWrite(motor_pwm_pin, speed_pwm);
  delay(10);

  
  }
  
