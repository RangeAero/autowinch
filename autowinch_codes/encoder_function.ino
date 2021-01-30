void setup_Encoder(){

  
  pinMode(encoder_pin_A, INPUT); 
  pinMode(encoder_pin_B, INPUT);
  digitalWrite(encoder_pin_A, HIGH); //turn pullup resistor on
  digitalWrite(encoder_pin_B, HIGH); //turn pullup resistor on
  attachInterrupt(digitalPinToInterrupt(encoder_pin_A), updateEncoder, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(encoder_pin_B), updateEncoder, CHANGE);
  }


void updateEncoder(){
  int MSB = digitalRead(encoder_pin_A); //MSB = most significant bit
  int LSB = digitalRead(encoder_pin_B); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;

  lastEncoded = encoded; //store this value for next time
}
