#define MOTOR_DIR 5
#define PWM_PIN 4
bool dir_output = LOW;
void setup(){
  pinMode(MOTOR_DIR, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  dir_output = !dir_output;
  digitalWrite(MOTOR_DIR, dir_output);
  for(int i=0; i<100; i++){
      analogWrite(PWM_PIN, i);
        delay(100);
    }
}
