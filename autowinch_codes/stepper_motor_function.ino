void setup_Stepper(){
   pinMode(stepper_step_pin, OUTPUT); 
   pinMode(stepper_dir_pin, OUTPUT);
  }

void move_stepper(int n_step){
   
   int dir = ((n_step/abs(n_step)) +1)/2;
   n_step = abs(n_step);
   digitalWrite(stepper_dir_pin, dir*255);
   for(int i = 0; i<n_step; i++){
    digitalWrite(stepper_step_pin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepper_step_pin, LOW);
    delayMicroseconds(800);
    }
  }
