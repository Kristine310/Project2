#include<stdio.h>
#include "kristine.h"

//Find seminar and conference registration fees and add them to the total expenses
void semConRegistrationFees(double totalExpenses)
{
    char userInput; 
    int invalid1 = -1;
    do
    {
        printf("Do you have any seminar or conference registration fees? ");
        scanf("%c", &userInput);
        if (userInput == 'Y' || userInput == 'y')
        {
            double prices;
            int invalid2 = -1;
            do
            {
                printf("Enter the seminar or conference registration fees: ");
                scanf("%lf", &prices);
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