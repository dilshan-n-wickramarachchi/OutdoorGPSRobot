#include <math.h>
#include <stdio.h>
#define remender( x, y )

float getRadain(float degrees) {
  return degrees * PI / 180;
}

float getDistance(float lat1, float lon1, float lat2, float lon2) {
  float earthRadiusKm = 6371;

  float dLat = getRadain(lat2-lat1);
  float dLon = getRadain(lon2-lon1);

  lat1 = getRadain(lat1);
  lat2 = getRadain(lat2);

  float a = sin(dLat/2) * sin(dLat/2) +
          (sin(dLon/2) * sin(dLon/2)) * (cos(lat1) * cos(lat2)); 
  float c = 2 *atan2(sqrt(a), sqrt(1-a)); 
  return (earthRadiusKm * c)*1000; //return distance in meters
  
}

float getAngle(float lat1, float long1, float lat2,float long2) {
  float deltalong=(long2-long1);
  float angle=atan2(sin(deltalong)*cos(lat2),cos(lat1)*sin(lat2)-sin(lat1)*cos(lat2)*cos(deltalong));
  angle=angle*180.0/PI;
  angle=angle+360;
  angle=fmodf(angle,360);
  return angle;
}
