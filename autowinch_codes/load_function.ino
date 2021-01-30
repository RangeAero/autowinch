void setup_HX711(){
  
  scale.begin(hx711_data_pin, hx711_clk_pin);
  scale.set_scale(calibration_factor);
  scale.tare();  //Reset the scale to 0
  }


float read_Scale(){
  return (scale.get_units());
  }
