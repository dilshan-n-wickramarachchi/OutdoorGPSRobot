#include <compass.h>
#include "Ublox.h"
#define SERIAL_BAUD 9600
#define GPS_BAUD 9600
#define N_FLOATS 2
#include <Wire.h>
#include "compass.h"

//GPS
Ublox M8_Gps;
float gpsArray[N_FLOATS] = {0, 0};  // Latitude - Longitude


//Motor Drive
//Front wheels
const int f_pwm1_L = 11 ;      //initializing pin 6 as pwm4 11 43 41
const int f_in_L1 = 43 ;    //L1,L2 connected for Front Left wheel
const int f_in_L2 = 41;

const int f_pwm1_R = 10 ;
const int f_in_R1 = 37 ;   //R1,R2 connected for Front Right wheel 10 37 39
const int f_in_R2 = 39 ;

//Rear wheels
const int r_pwm1_R = 12 ;    //initializing pin 6 as pwm
const int r_in_L1 = 51;     //L1,L2 connected for Rear Left wheel
const int r_in_L2 = 49;

const int r_pwm1_L = 13 ;
const int r_in_R1 = 45;      //R1,R2 connected for Rear Right wheel
const int r_in_R2 = 47 ;

int s1 = 250;
int s2 = 200;

//Special variable
float distance;
float e_angle;
float r_angle;
float clat;
float clon;

//Final coordinate details
float flat = 6.797201;
float flon = 79.900665;
float slat;
float slon;

void setup() {
  // GPS
  Serial.begin(SERIAL_BAUD);
  Serial1.begin(GPS_BAUD);

  //Motor drive
  //Initialize front wheel motor driver
  pinMode(f_pwm1_L, OUTPUT) ;
  pinMode(f_pwm1_R, OUTPUT) ;
  pinMode(f_in_L1, OUTPUT) ;
  pinMode(f_in_L2, OUTPUT) ;
  pinMode(f_in_R1, OUTPUT) ;
  pinMode(f_in_R2, OUTPUT) ;

  //Initalize Rear wheel motor driver
  pinMode(r_pwm1_L, OUTPUT) ; //we have to set PWM pin as output
  pinMode(r_pwm1_R, OUTPUT) ;
  pinMode(r_in_L1, OUTPUT) ; //Logic pins are also set as output
  pinMode(r_in_L2, OUTPUT) ;
  pinMode(r_in_R1, OUTPUT) ; //we have to set PWM pin as output
  pinMode(r_in_R2, OUTPUT) ; //Logic pins are also set as output

  //Compass
  compass_calibrate();

  //Starting point GPS
  getGPS();
  slon = gpsArray[1];
  slat = gpsArray[0];
}

void loop() {
  getGPS();
  clon = gpsArray[1];
  clat = gpsArray[0];

  distance = getDistance( clat,  clon,  flat,  flon);
  r_angle = getAngle( clat,  clon,  flat,  flon);
  e_angle = heading() - r_angle;

  //Start motion
  while (distance > 5 or abs(e_angle) > 5 ) {
    e_angle = heading() - r_angle;
    while (abs(e_angle) > 5 ) {
      e_angle = heading() - r_angle;
      if ( -180 < e_angle and e_angle < -5) { //turn right
        right_rotate(175);
      } else if (180 > e_angle and e_angle > 5) { // turn left
        left_rotate(175);
      } else { // forced break
        active_break();
      }
    }
    while (distance > 5 ) {
      forw(200);
      getGPS();
      clon = gpsArray[1];
      clat = gpsArray[0];
      distance = getDistance( clat,  clon,  flat,  flon);

      if (distance <= 5) {
        break;
      }
    }

    getGPS();
    clon = gpsArray[1];
    clat = gpsArray[0];

    distance = getDistance( clat,  clon,  flat,  flon);
    r_angle = getAngle( clat,  clon,  flat,  flon);
    e_angle = heading() - r_angle;
  }
}
