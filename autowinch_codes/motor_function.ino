void setup_Motor(){
   pinMode(motor_pwm_pin, OUTPUT); 
   pinMode(motor_dir_pin, OUTPUT);
  
  }

void run_motor(int dir, int speed_pwm){
  digitalWrite(motor_dir_pin, dir*255);
  digitalWrite(motor_pwm_pin, speed_pwm);

  
  }
  
