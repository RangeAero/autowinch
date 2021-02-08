float get_reference(float err){
  sum_err += err;
  float del_err = err - prev_err;
  ref = gain_p*err + gain_d*del_err + gain_i*sum_err;
  prev_err = err;

   return ref;
  
  }

void move_spool(int motor_speed){
  
  motor_speed = motor_factor*motor_speed;
  int dir = ((motor_speed/abs(motor_speed)) +1)/2;
  if(motor_speed>255 || motor_speed <-255)
    motor_speed = 255;
  else
    motor_speed = abs(motor_speed);

  
  run_motor(dir, motor_speed);
  //move_stepper(dir, step_factor*abs(steps));
  
  }

void move_slider(){
  curr_encoder = encoderValue;
  int del_encode_value =  curr_encoder-prev_Encoded;
  float steps = 50*del_encode_value/4000;
  
  steps = dir_flag*steps;
  steps = round(steps);
  move_stepper(steps);
  if(steps !=0)
  prev_Encoded = curr_encoder;
  
  
  }  
