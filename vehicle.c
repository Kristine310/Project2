#include <stdio.h>
#include "vehicle1.h"

float returnTaxiExpenses;
float returnParkExpenses;
float savedTaxiExpenses;
float savedParkExpenses;
float costParkAllowed;
float costTaxiAllowed;

//amount of any car rental 
float carRental(float totalExpenses) 
{   int carRental;
    char response;
    int invalid1 = -1;
    do
    {
        printf("Did you purchase a car rental (Y/N): ");
        scanf("%s", response);
        int invalid2 = -1;
        if (response == 'Y' || response == 'y')
        {
            do
            {
            printf("Enter the total amount of any car rentals: \n");
            scanf("%f", &carRental);
            if (carRental > 0)
            {
                invalid2 = 1;
                totalExpenses = totalExpenses + carRental;
            }
            else
            {
                printf("Amount is invalid\n");
            }
            } while (invalid2 < 0);
        }
        else if (response == 'N' || response == 'n')
        {
            invalid2 = 1;
        }
        else
        {
            printf("Invalid response");
        }
    } while (invalid1 < 0);
 return totalExpenses;
}

// costs miles driven if a private vehicle was used (calculate the vehicle expense as $0.27 per mile driven)
 float costMiles(int tripDays, float totalExpenses)
 {
     float milesDriven;
     const float vehicleExpenseMD = 0.27;
     char response;
     int invalid1 = -1;
    do
    {
        printf("Did you use a private vehicle (Y/N): ");
        scanf("%s", response);
        int invalid2 = -1;
        if (response == 'Y' || response == 'y')
        {
            do
            {
            printf("Enter the total miles driven: \n");
            scanf("%f", &milesDriven);
            if (milesDriven > 0)
            {
                invalid2 = 1;
                totalExpenses = totalExpenses + (milesDriven * vehicleExpenseMD);
            }
            else
            {
                printf("Amount is invalid\n");
            }
            } while (invalid2 < 0);
        }
        else if (response == 'N' || response == 'n')
        {
            invalid2 = 1;
        }
        else
        {
            printf("Invalid response");
        }
    } while (invalid1 < 0);
    return totalExpenses; 
}

// costs parking (The company allows up to $6 per day. Anything more than this must be paid by the employee.)
float costParking(int tripDays, float totalExpenses)
{
     float parkingExpense; 
     const float parkFeesAllowed = 6.00;
     for (int i = 0; i < tripDays; i++)
     {
        costParkAllowed = costParkAllowed + parkFeesAllowed;
        int notValid = -1;
        do
        {
            printf("Enter the total amount spent on Parking Fees: \n");
            scanf("%s", parkingExpense);
            if (parkingExpense > 0)
            {
                notValid = 1;
                totalExpenses = totalExpenses + parkingExpense;
                if (parkingExpense > parkFeesAllowed)
                {
                    returnParkExpenses = returnParkExpenses + (parkingExpense - parkFeesAllowed);
                }
                else
                {
                    savedParkExpenses = savedParkExpenses + parkingExpense;
                }
            }
            else
            {
                printf("Invalid price.");
            }
        } while (notValid < 0);   
    }
    return totalExpenses;
}         

// costs taxi (if a taxi was used anytime during the trip (The company allows up to $10 per day, for each day a taxi was used. Anything more than this must be paid by the employee.) 
float costTaxis(int tripDays, float totalExpenses)
{ 
     float taxiExpense;
     const float taxiFeesAllowed = 10.00;
     char response;
     int invalid1 = -1;
    do
    {
        printf("Did you use any taxi (Y/N): ");
        scanf("%s", response);
        int invalid2 = -1;
        if (response == 'Y' || response == 'y')
        {
             float taxiExpense; 
             const float taxiFeesAllowed = 6;
             for (int i = 0; i < tripDays; i++)
             {
                costTaxiAllowed = costTaxiAllowed + taxiFeesAllowed;
                int invalid3 = -1;
                do
                {
                    printf("Enter the total amount spent on taxi fees: \n");
                    scanf("%f", taxiExpense);
                    if (taxiExpense > 0)
                    {
                        invalid3 = 1;
                        totalExpenses = totalExpenses + taxiExpense;
                        if (taxiExpense > costTaxiAllowed)
                        {
                            returnTaxiExpenses = returnTaxiExpenses + (taxiExpense - taxiFeesAllowed);
                        }
                        else
                        {
                            savedTaxiExpenses = savedTaxiExpenses + taxiExpense;
                        }
                    }
                    else
                    {
                        printf("Invalid price.");
                    }
                } while (invalid3 < 0);
             }
        }
        else if (response == 'N' || response == 'n')
        {
            invalid2 = 1;
        }
        else
        {
            printf("Invalid response");
        }
    } while (invalid1 < 0);
    return totalExpenses;
}

