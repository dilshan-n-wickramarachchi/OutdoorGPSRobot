/* Andrea Toscano
Universita' degli Studi di Milano

Sample script - Reading some info from U-Blox Neo M8N GPS/GLONASS
*/

#include "Ublox.h"
#define SERIAL_BAUD 9600
#define GPS_BAUD 9600
#define N_FLOATS 4

//Special variable 
float distance;
float e_angle;
float r_angle;
float clat;
float clon;

//Final coordinate details
float flat=6.797201;
float flon=79.900665;
float slat;
float slon;

Ublox M8_Gps;
// Altitude - Latitude - Longitude - N Satellites
float gpsArray[N_FLOATS] = {0, 0, 0, 0};

void setup() {
   Serial.begin(SERIAL_BAUD);
   Serial1.begin(GPS_BAUD);
 
}

void loop() {
   if(!Serial1.available())
		return;
  //delay(1000);
  while(Serial1.available()){
        char c = Serial1.read();
         if (M8_Gps.encode(c)) {
          gpsArray[0] = M8_Gps.altitude;
          gpsArray[1] = M8_Gps.latitude;
          gpsArray[2] = M8_Gps.longitude; 
          gpsArray[3] = M8_Gps.sats_in_use;

          distance = getDistance( clat,  clon,  flat,  flon);
          //r_angle = getAngle( clat,  clon,  flat,  flon);
         // e_angle = heading() - r_angle;
        }
  }
  for(byte i = 0; i < N_FLOATS; i++) {
    Serial.print(gpsArray[i], 10);Serial.print("               ");Serial.print(distance);
    
  }
  Serial.println("");
}

