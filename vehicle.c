#include <stdio.h>
#include "vehicle1.h"

//amount of any car rental 
float carRental(float totalExpenses) 
{   int carRental;
    char response;
    int invalid1 = -1;
    do
    {
        printf("Did you purchase a car rental (Y/N): ");
        scanf("%c", response);
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
            } while (invalid2 < 0)
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
 float costMilesCov(int tripDays, float totalExpenses)
 {
     float vehicleExpense;
     char response;
     int invalid1 = -1;
    do
    {
        printf("Did you use a private vehicle (Y/N): ");
        scanf("%c", response);
        int invalid2 = -1;
        if (response == 'Y' || response == 'y')
        {
            do
            {
            printf("Enter the total costs of miles driven: \n");
            scanf("%f", &vehicleExpense);
            if (vehicleExpense > 0)
            {
                invalid2 = 1;
                totalExpenses = totalExpenses + vehicleExpense;
            }
            else
            {
                printf("Amount is invalid\n");
            }
            } while (invalid2 < 0)
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
}

// costs parking (The company allows up to $6 per day. Anything more than this must be paid by the employee.)
void costParkingCov (int tripDays, float totalExpenses, float returnExpenses, float savedExpenses, float allowableExpenses)
{
     float parkingExpense; 
     const float costParkAllowed = 6.00;
     for (int i = 0; i < tripDays; i++)
     {
        allowableExpenses = allowableExpenses + costParkAllowed;
        int notValid = -1;
        do
        {
            printf("Enter the total amount spent on Parking Fees: \n company allows up to $6 per day"): ", i);
            scanf("%f", parkingExpense);
            if (parkingExpense > 0)
            {
                notValid = 1;
                totalExpenses = totalExpenses + parkingExpense;
                if (parkingExpense > costParkAllowed)
                {
                    returnExpenses = returnExpenses + (parkingExpense - costParkAllowed);
                }
                else
                {
                    savedExpenses = savedExpenses + parkingExpense;
                }
            }
            else
            {
                printf("Invalid price.");
            }
        } while (notValid < 0);
        
    }
}         

// costs taxi (if a taxi was used anytime during the trip (The company allows up to $10 per day, for each day a taxi was used. Anything more than this must be paid by the employee.) 
void costTaxisCov(int tripDays, float totalExpenses, float returnExpenses, float savedExpenses, float allowableExpenses)
 {   
     char response;
     int invalid1 = -1;
    do
    {
        printf("Did you use any taxi (Y/N): ");
        scanf("%c", response);
        int invalid2 = -1;
        if (response == 'Y' || response == 'y')
        {
             float parkingExpense; 
             const float costParkAllowed = 6;
             for (int i = 0; i < tripDays; i++)
             {
                allowableExpenses = allowableExpenses + costParkAllowed;
                int notValid = -1;
                do
                {
                    printf("Enter the total amount spent on Parking Fees: \n company allows up to $6 per day"): ", i);
                    scanf("%f", parkingExpense);
                    if (parkingExpense > 0)
                    {
                        notValid = 1;
                        totalExpenses = totalExpenses + parkingExpense;
                        if (parkingExpense > costParkAllowed)
                        {
                            returnExpenses = returnExpenses + (parkingExpense - costParkAllowed);
                        }
                        else
                        {
                            savedExpenses = savedExpenses + parkingExpense;
                        }
                    }
                    else
                    {
                        printf("Invalid price.");
                    }
                 } while (notValid < 0);
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
 }

