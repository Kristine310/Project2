#include <stdio.h>
#include "vehicle1.h"

/* if a taxi was used anytime during the trip (The company allows up to $10 per day, 
for each day a taxi was used. Anything more than this must be paid by the employee.) 
The company allows up to $6 per day. Anything more than this must be paid by the employee.
 a private vehicle was used. Calculate the vehicle expense as $0.27 per mile driven 
 */ 

float vehicleExpense;
float parkingExpense;

//amount of any car rental 
int carRental(float totalExpenses) 
{  int carRental; 
    printf("Enter the total amount of any car rentals: \n");
    scanf("%f", &carRental); 
}

// costs miles driven (covered)
 float costMilesCov(int tripDays, float totalMiles)
 {
     printf("Enter the total costs of miles driven: ");
     scanf("%f", &vehicleExpense);
     float vehicleExpense = 0;
     vehicleExpense = totalMiles * 0.27;
      while(vehicleExpense<0){
        printf("Error: Not a valid input! vehicleExpense cannot be negative.\n Please reenter: ");
        scanf("%f", &vehicleExpense);
    }
     return vehicleExpense;
 }

// costs parking (covered)
 float costParkingCov (int daysSpent)
 {
     printf("Enter the total amount spent on Parking Fees: \n");
        scanf("%f", &parkingExpense);
     float parkingExpense = 0;
     parkingExpense = daysSpent * 6.00;
     parkingExpense = totalMiles * 0.27;
      while(parkingExpense<0){
        printf("Error: Not a valid input! vehicleExpense cannot be negative.\n Please reenter: ");
        scanf("%f", &parkingExpense);
    }
     return parkingExpense;
 }

// costs taxi (covered) 
 float costTaxisCov(int daysSpent)
 {
     printf("Enter the total amount spent on Taxi Fees: \n");
        scanf("%f", &taxiExpense);
     float taxiExpense = 0;
     taxiExpense = daysSpent * 10.00;
     taxiExpense = totalMiles * 0.27;
      while(taxiExpense<0){
        printf("Error: Not a valid input! vehicleExpense cannot be negative.\n Please reenter: ");
        scanf("%f", &taxiExpense);
    }
     return taxiExpense;
 }

