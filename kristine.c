#include "kristine.h"
#include<stdio.h>

float hotelReturned, hotelSaved, hotelAllowed;

//Find seminar and conference registration fees and add them to the total expenses
float semConRegistrationFees(float totalExpenses)
{
    char userInput; 
    int invalid1 = -1;
    do
    {
        printf("Do you have any seminar or conference registration fees? (Y/N)\n");
        scanf("%s", &userInput);
        if (userInput == 'Y' || userInput == 'y')
        {
            float prices;
            int invalid2 = -1;
            do
            {
                printf("Enter the seminar or conference registration fees: ");
                scanf("%f", &prices);
                if (prices <= 0)
                {
                    printf("Invalid fees. Please submit again.\n");
                }
                else
                {
                    totalExpenses = totalExpenses + prices;
                    invalid2 = 1;
                }
            } while (invalid2 < 0);
            invalid1 = 1;
        }
        else if (userInput == 'N' || userInput == 'n')
        {
            invalid1 = 1;
        }
        else
        {
            printf("Invalid input\n");
        }
    } while (invalid1 < 0);
    return totalExpenses;
}

//Calculate the hotel expenses (company allows $90 per night, extra is payed by employee)
float hotelExpenses(int tripDays, float totalExpenses)    
{
    float hotelCost; 
    const float MAX_ALLOWED = 90;
    int i;
    for (i = 0; i < tripDays - 1; i++)
    {
        hotelAllowed = hotelAllowed + MAX_ALLOWED;
        int invalid = -1;
        do
        {
            printf("Enter the hotel room cost for night %d (the company allows $90 per night): ", i + 1);
            scanf("%f", &hotelCost);
            if (hotelCost > 0)
            {
                invalid = 1;
                totalExpenses = totalExpenses + hotelCost;
                if (hotelCost > MAX_ALLOWED)
                {
                    hotelReturned = hotelReturned + (hotelCost - MAX_ALLOWED);
                }
                else
                {
                    hotelSaved = hotelSaved + hotelCost;
                }
            }
            else
            {
                printf("Invalid price.\n");
            }
        } while (invalid < 0); 
    }
    return totalExpenses;
}