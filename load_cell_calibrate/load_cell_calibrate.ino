#include "HX711.h"
#define hx711_clk_pin A0
#define hx711_data_pin A1
#define SCALE 450.31
HX711 scale;

void setup() {
  // put your setup code here, to run once:
  scale.begin(hx711_data_pin, hx711_clk_pin);
  scale.set_scale(); 
  scale.tare(); 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  scale.set_scale(SCALE);
  float weight = scale.get_units(10);
  Serial.print("weight: ");
  Serial.println(weight);

}
