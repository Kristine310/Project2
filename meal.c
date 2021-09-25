#include <stdio.h> 
#include "meal1.h"

int breakfastAllowed(int timeDept, int timeArrival, int numDays)
{
    int breakfast = 0; 

    if (numDays > 2)
        breakfast = breakfast + numDays -2;

    if (timeDept < 7)
        breakfast++;
    
    if (timeArrival > 8)
        breakfast++;

    return breakfast; 
}

int lunchAllowed(int timeDept, int timeArrival, int numDays)
{
    int lunch = 0; 

    if (numDays > 2)
        lunch = lunch + numDays -2;

    if (timeDept < 7)
        lunch++;
    
    if (timeArrival > 8)
        lunch++;

    return lunch; 
}

int dinnerAllowed(int timeDept, int timeArrival, int numDays)
{
    int dinner = 0; 

    if (numDays > 2)
        dinner = dinner + numDays -2;

    if (timeDept < 7)
        dinner++;
    
    if (timeArrival > 8)
        dinner++;

    return dinner; 
}

float costAlloted(int timeDept, int timeArrival, int numDays)
{
    int breakfastCost = breakfastAllowed(timeDept, timeArrival, numDays) * 9)
    int lunchCost = lunchAllowed(timeDept, timeArrival, numDays) * 12)
    int dinnerCost = dinnerAllowed(timeDept, timeArrival, numDays) * 16)
    float sum = (float)breakfastCost + lunchCost + dinnerCost;
    return sum; 
}