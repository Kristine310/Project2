#ifndef TRIPDURATION_H
#define TRIPDURATION_H

extern int tripLength, globalHours, globalMinutes;
extern char departureTime[5];
extern char arrivalTime[5];
extern float roundTripCost;

int tripDuration();
int tripDeparture();
int tripArrival();
float totalAirfare ();
int timeValidation(char time[]);

#endif