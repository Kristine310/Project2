#ifndef VEHICLE1_H
#define VEHICLE1_H

extern float returnTaxiExpenses, returnParkExpenses, savedTaxiExpenses,savedParkExpenses, costParkAllowed, costTaxiAllowed; 

float carRental(float totalExpenses);
float costMiles(int tripDays, float totalExpenses);
float costParking(int tripDays, float totalExpenses);
float costTaxis(int tripDays, float totalExpenses);
 
 #endif
