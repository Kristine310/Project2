#include<stdio.h>
#include "kristine.h"

//Find seminar and conference registration fees and add them to the total expenses
void semConRegistrationFees(float totalExpenses)
{
    char userInput; 
    int invalid1 = -1;
    do
    {
        printf("Do you have any seminar or conference registration fees? ");
        scanf("%c", &userInput);
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
                    printf("Invalid fees. Please submit again.");
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
}

//Calculate the hotel expenses (company allows $90 per night, extra is payed by employee)
void hotelExpenses(int tripDays, float totalExpenses, float returnExpenses, float savedExpenses, float allowableExpenses)    
{
    float hotelCost; 
    const float MAX_ALLOWED = 90;
    for (int i = 0; i < tripDays - 1; i++)
    {
        allowableExpenses = allowableExpenses + MAX_ALLOWED;
        int invalid = -1;
        do
        {
            printf("Enter the hotel room cost for night %d (the company allows $90 per night): ", i);
            scanf("%lf", hotelCost);
            if (hotelCost > 0)
            {
                invalid = 1;
                totalExpenses = totalExpenses + hotelCost;
                if (hotelCost > MAX_ALLOWED)
                {
                    returnExpenses = returnExpenses + hotelCost;
                }
                else
                {
                    savedExpenses = savedExpenses + hotelCost;
                }
            }
            else
            {
                printf("Invalid price.");
            }
        } while (invalid < 0);
        
    }
}