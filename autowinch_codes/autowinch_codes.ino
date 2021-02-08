//#include <HX711.h>
#include "HX711.h"

#define positive 1
#define negative 0



#define encoder_pin_A 2  //white
#define encoder_pin_B 3   // green

#define stepper_step_pin 4
#define stepper_dir_pin 5  

#define motor_dir_pin 6
#define motor_pwm_pin 7

#define limit_switch_pin_left 18
#define limit_switch_pin_right 19

#define hx711_clk_pin A0
#define hx711_data_pin A1

#define step_factor 1
#define motor_factor 0.1


//declare variable for controller gain
#define gain_p 1
#define gain_i 0.001
#define gain_d 0.02



//intialise variables for encoder
volatile int lastEncoded = 0;
volatile long encoderValue = 0;
volatile long curr_encoder = 0;
long lastencoderValue = 0;
int lastMSB = 0;
int lastLSB = 0;
volatile int prev_Encoded = 0;

//declare load cell variable
HX711 scale;
#define calibration_factor 450.31 //1961.0


//declare variable for defining rotation of lead screw
int dir_flag = 1;

//declare variable to be used in loop loop
float err = 0;
float prev_err = 0;
float sum_err = 0;
float ref = 0;




void setup() {
 setup_Encoder();//setup the pins for encoder
 setup_Stepper();//setup the pins for stepper
 setup_Motor();//setup the pins for motor
 setup_Limit_switch();//setup the pins for limit switches
 //setup_HX711();//blocking function
 Serial.begin(9600);
}

void loop() {
  
  //ref = get_reference(round(read_Scale())); //estimate input signal for no. of steps by reading load cell
  //Serial.print("Motor speed ref: ");
  //Serial.println(ref);
  //if(ref <= -50 || ref >= 50)
    //move_spool(round(ref));
  //else 
    //move_spool(0);
    // turn the LED off by making the voltage LOW
  //Serial.print("Encoder value:   ");
  //Serial.println(encoderValue);
  move_slider();
  

 
//Serial.println(" ");
  
  //Serial.print("Load cell:   ");
  //1Serial.println(read_Scale());
  //Serial.print("Encoder value:   ");
  //Serial.println(encoderValue);
  //delay(50);
  // put your main code here, to run repeatedly:

}
