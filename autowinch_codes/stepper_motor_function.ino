void setup_Stepper(){
   pinMode(stepper_step_pin, OUTPUT); 
   pinMode(stepper_dir_pin, OUTPUT);
  }

void move_stepper(int n_step){
   
   int dir = ((n_step/abs(n_step)) +1)/2;
   n_step = abs(n_step);
   if (dir == 1){
    Serial.println("dir == HIGH");
    digitalWrite(stepper_dir_pin, HIGH);
   }
   else{ 
    Serial.println("working");
      digitalWrite(stepper_dir_pin, LOW);
   }
   for(int i = 0; i<n_step; i++){
    digitalWrite(stepper_step_pin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepper_step_pin, LOW);
    delayMicroseconds(800);
    }
  }
