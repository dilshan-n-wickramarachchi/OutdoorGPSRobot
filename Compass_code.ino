#include <Wire.h>
#include "compass.h"

#define Task_t 10          // Task Time in milli seconds
int dt=0;
unsigned long t;
// Main code -----------------------------------------------------------------
void compass_calibrate(){
  
  // Serial.print("Setting up I2C ........\n");
  Wire.begin();
  compass_x_offset = 122.17;
  compass_y_offset = 230.08;
  compass_z_offset = 389.85;
  compass_x_gainError = 1.12;
  compass_y_gainError = 1.13;
  compass_z_gainError = 1.03;
  compass_init(2);
  compass_debug = 1;
  compass_offset_calibration(3);

}

// Main loop 
// Main loop -----------------------------------------------------------------
float heading(){
  compass_heading();
  //Serial.print ("Heading angle = ");
  //Serial.print (bearing);
  //Serial.println(" Degree");
  return bearing;
  delay(100);
}

