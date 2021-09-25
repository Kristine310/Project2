#ifndef TRIPDURATION_H
#define TRIPDURATION_H

extern int tripLength;
extern char departureTime[5];
extern char arrivalTime[5];
extern float roundTripCost;

int tripDuration();
int tripDeparture();
int tripArrival();
float totalAirfare ();

#endif