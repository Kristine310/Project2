#include<stdio.h>
#include<string.h>
#include "kristine.h"
 
 int main()
 {
     char arriveTime[5], departTime[5];
     float totalExpenses, savedExpenses, returnExpenses, allowedExpenses;
     int tripDays;

     printf("You have been on a trip for %d days from %s to %s.\n", tripDays, arriveTime, departTime);
     printf("Total expenses: $%f\n", totalExpenses);
     printf("Total allowable expenses: $%f\n", allowedExpenses);
     printf("Amount reimbursement: $%f\n", returnExpenses);
     printf("Amount saved: $%f\n", savedExpenses);

     return 0;
 }