#ifndef TRIPDURATION_H
#define TRIPDURATION_H

extern int tripLength;
extern char[] departureTime;
extern char[] arrivalTime;
extern float roundTripCost;

int tripDuration();
char[] tripDeparture ();
char[] tripArrival ();
float totalAirfare ();

#endif