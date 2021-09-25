#ifndef TRIPDURATION_H
#define TRIPDURATION_H

extern int tripLength;
extern char[5] departureTime;
extern char[5] arrivalTime;
extern float roundTripCost;

int tripDuration();
int tripDeparture();
int tripArrival();
float totalAirfare ();

#endif