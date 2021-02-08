void setup_Motor(){
   pinMode(motor_pwm_pin, OUTPUT); 
   pinMode(motor_dir_pin, OUTPUT);
  
  }

void run_motor(int dir, int speed_pwm){
  if (dir == 0)
    digitalWrite(motor_dir_pin, HIGH );
  else
     digitalWrite(motor_dir_pin, LOW );
  analogWrite(motor_pwm_pin, speed_pwm); 
}
  
