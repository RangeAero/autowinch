void setup_Stepper(){
   pinMode(stepper_step_pin, OUTPUT); 
   pinMode(stepper_dir_pin, OUTPUT);
   pinMode(stepper_ena_pin, LOW);
   digitalWrite(stepper_dir_pin, LOW);
   digitalWrite(stepper_ena_pin, LOW);
}

void move_stepper(int n_step){
   int dir = ((n_step/abs(n_step)) +1)/2;
   n_step = abs(n_step);
   //Serial.print("dc moto direction");
   //Serial.println(dir);
   if (dir == 1){
    digitalWrite(stepper_dir_pin, HIGH);
   }
   else if(dir == 0){ 
      digitalWrite(stepper_dir_pin, LOW);
   }
   for(int i = 0; i<n_step; i++){
    digitalWrite(stepper_step_pin, HIGH);
    delayMicroseconds(99900);
    digitalWrite(stepper_step_pin, LOW);
    delayMicroseconds(99900);
    }
    
   
}
