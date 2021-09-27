/*
One of our teammates, Ayanna, did not contribute to the project.
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "kristine.h"
#include "meal1.h"
#include "tripDuration.h"
#include "vehicle1.h"
 
 int main()
 {
     char arriveTime[5], departTime[5];
     float totalExpenses = 0.00; 
     float savedExpenses = 0.00; 
     float returnExpenses = 0.00;
     float allowedExpenses = 0.00;
     int tripDays;
     
     //Trip days
     tripDays = tripDuration();
     //Arrival Time
     int in = tripArrival();
     //Departure Time
     int out = tripDeparture();
     //Cost of airfare
     totalExpenses = totalExpenses + totalAirfare();
     //Cost of car rental
     totalExpenses = carRental(totalExpenses);
     //Cost of miles driven in private car
     totalExpenses = costMiles(tripDays, totalExpenses);
     //Cost of parking
     totalExpenses = costParking(tripDays, totalExpenses);
     savedExpenses += savedParkExpenses;
     returnExpenses += returnParkExpenses;
     allowedExpenses += costParkAllowed;
     //Cost of taking a taxi
     totalExpenses = costTaxis(tripDays, totalExpenses);
     savedExpenses += savedTaxiExpenses;
     returnExpenses += returnTaxiExpenses;
     allowedExpenses += costTaxiAllowed;
     //Cost of seminar/conference registration
     totalExpenses = semConRegistrationFees(totalExpenses);
     //Cost of hotels per night
     totalExpenses = hotelExpenses(tripDays, totalExpenses);
     savedExpenses += hotelSaved;
     returnExpenses += hotelSaved;
     allowedExpenses += hotelAllowed;
     //Cost of meals each day
     totalExpenses = totalExpenses + getTotalMealCosts();
     savedExpenses = savedExpenses + getSavedFoodMoney();
     returnExpenses = returnExpenses + getFoodDebtToCompany();
     allowedExpenses = allowedExpenses + getMaxMealExpenses();

     printf("You have been on a trip for %d days from %d:%d to %s.\n", tripDays, globalArrivalHours, globalArrivalMinutes, departureTime);
     printf("Total expenses: $%.2f\n", totalExpenses);
     printf("Total allowable expenses: $%.2f\n", allowedExpenses);
     printf("Amount reimbursement: $%.2f\n", returnExpenses);
     printf("Amount saved: $%.2f\n", savedExpenses);

     return 0;
 }