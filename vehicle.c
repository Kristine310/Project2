#include <stdio.h>
#include "vehicle1.h"

/* if a taxi was used anytime during the trip (The company allows up to $10 per day, 
for each day a taxi was used. Anything more than this must be paid by the employee.) 
The company allows up to $6 per day. Anything more than this must be paid by the employee.
 a private vehicle was used. Calculate the vehicle expense as $0.27 per mile driven 
 */ 

//amount of any car rental 
printf("Enter the total amount of any car rentals: \n");
        scanf("%f", &rentalFare);

// costs miles driven (covered)
 float costMilesCov(int totalMiles)
 {
     float vehicleExpense = 0;
     vehicleExpense = totalMiles * 0.27;
     return vehicleExpense;
 }

// costs parking (covered)
 float costParkingCov (int daysSpent)
 {
     float parkingExpense = 0;
     parkingExpense = daysSpent * 6.00;
     return parkingExpense;
 }

// costs taxi (covered) 
 float costTaxisCov(int daysSpent)
 {
     float taxiExpense = 0;
     taxiExpense = daysSpent * 10.00;
     return taxiExpense;
 }
