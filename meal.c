#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "meal1.h"
#include "tripDuration.h"

float totalMealCosts;
float maximumMealExpenses;
float foodDebtToCompany;
float savedFoodMoney;

int numberOfFirstDayMeals;
int numberOfLastDayMeals;

int getNumOfFirstDayMeals(){
    if(globalDepartureHours < 7){
        numberOfFirstDayMeals = 3;
    } else if(globalDepartureHours < 12){
        numberOfFirstDayMeals = 2;
    } else if(globalDepartureHours < 18){
        numberOfFirstDayMeals = 1;
    } else{
        numberOfFirstDayMeals = 0;
    }

    return numberOfFirstDayMeals;
}

int getNumOfLastDayMeals(){
    if(globalArrivalHours > 19 || (globalArrivalHours == 19 && globalArrivalMinutes > 0)){
        numberOfLastDayMeals = 3;
    } else if(globalArrivalHours > 13 || (globalArrivalHours == 13 && globalArrivalMinutes > 0)){
        numberOfLastDayMeals = 2;
    } else if (globalArrivalHours > 7 || (globalArrivalHours == 7 && globalArrivalMinutes > 0)){
        numberOfLastDayMeals = 1;
    } else{
        numberOfLastDayMeals = 0;
    }

    return numberOfLastDayMeals;
}


float getTotalMealCosts(){
    int dayCount;
    float tempCost = 0.0;


    //cost of meals on the first day
    getNumOfFirstDayMeals();
        
    if(numberOfFirstDayMeals == 3){
       goto threeMeals;
    } else if(numberOfFirstDayMeals == 2){
        goto twoMeals;
    } else if(numberOfFirstDayMeals == 1){
        goto oneMeal;
    } else{
        goto noMeals;
    }

    threeMeals:
        printf("How much was breakfast on day 1? $");
        scanf("%f", &tempCost);
        while(tempCost < 0){
            printf("Not a valid cost! Costs cannot be negative! Please reenter the cost: $");
            scanf("%f", &tempCost);
        }
        totalMealCosts += tempCost;
    
    twoMeals:
        printf("How much was lunch on day 1? $");
        scanf("%f", &tempCost);
        while(tempCost < 0){
            printf("Not a valid cost! Costs cannot be negative! Please reenter the cost: $");
            scanf("%f", &tempCost);
        }
        totalMealCosts += tempCost;
    
    oneMeal:
        printf("How much was dinner on day 1? $");
        scanf("%f", &tempCost);
        while(tempCost < 0){
            printf("Not a valid cost! Costs cannot be negative! Please reenter the cost: $");
            scanf("%f", &tempCost);
        }
        totalMealCosts += tempCost;

    noMeals:

    
    //cost of meals in-between first and last days
    for(dayCount = 2; dayCount < tripLength; dayCount++){
        printf("How much was breakfast on day %d? $", dayCount);
        scanf("%f", &tempCost);
        while(tempCost < 0){
            printf("Not a valid cost! Costs cannot be negative! Please reenter the cost: $");
            scanf("%f", &tempCost);
        }
        totalMealCosts += tempCost;

        printf("How much was lunch on day %d? $", dayCount);
        scanf("%f", &tempCost);
        while(tempCost < 0){
            printf("Not a valid cost! Costs cannot be negative! Please reenter the cost: $");
            scanf("%f", &tempCost);
        }
        totalMealCosts += tempCost;

        printf("How much was dinner on day %d? $", dayCount);
        scanf("%f", &tempCost);
        while(tempCost < 0){
            printf("Not a valid cost! Costs cannot be negative! Please reenter the cost: $");
            scanf("%f", &tempCost);
        }
        totalMealCosts += tempCost;
    }
    

    //cost of meals on the last day
    if(tripLength>1){
        getNumOfLastDayMeals();

        if(numberOfLastDayMeals == 0){
          goto skip;
        }
    
        printf("How much was breakfast on the last day? $");
        scanf("%f", &tempCost);
        while(tempCost < 0){
            printf("Not a valid cost! Costs cannot be negative! Please reenter the cost: $");
            scanf("%f", &tempCost);
        }
        totalMealCosts += tempCost;
        if(numberOfLastDayMeals == 1){
           goto skip;
        }

        printf("How much was lunch on the last day? $");
        scanf("%f", &tempCost);
        while(tempCost < 0){
            printf("Not a valid cost! Costs cannot be negative! Please reenter the cost: $");
            scanf("%f", &tempCost);
        }
        totalMealCosts += tempCost;
        if(numberOfLastDayMeals == 2){
            goto skip;
        }

        printf("How much was dinner on the last day? $");
        scanf("%f", &tempCost);
        while(tempCost < 0){
            printf("Not a valid cost! Costs cannot be negative! Please reenter the cost: $");
            scanf("%f", &tempCost);
        }
        totalMealCosts += tempCost;
    }
    
    skip:
    return totalMealCosts;
}



float getMaxMealExpenses(){
    int tempDays = tripLength - 2;
    if(tripLength < 2){
        tempDays = 0;
    }
    float mealsThroughoutTrip = (float) (tempDays) * (9+12+16);
    float firstDayMeals = 0;
    float lastDayMeals = 0;

    if(globalDepartureHours < 7){
        firstDayMeals = 9 + 12 + 16;
    } else if(globalDepartureHours < 12){
        firstDayMeals = 12 + 16;
    } else if(globalDepartureHours < 18){
        firstDayMeals = 16;
    } else{
        firstDayMeals = 0;
    }
    
    if(globalArrivalHours > 19 || (globalArrivalHours == 19 && globalArrivalMinutes > 0)){
        lastDayMeals = 9 + 12 + 16;
    } else if(globalArrivalHours > 13 || (globalArrivalHours == 13 && globalArrivalMinutes > 0)){
        lastDayMeals = 9 + 12;
    } else if (globalArrivalHours > 7 || (globalArrivalHours == 7 && globalArrivalMinutes > 0)){
        lastDayMeals = 9;
    } else{
        lastDayMeals = 0;
    }
    
    maximumMealExpenses = firstDayMeals + mealsThroughoutTrip + lastDayMeals;
    return maximumMealExpenses;
}

float getFoodDebtToCompany(){
    getMaxMealExpenses();
    
    if(maximumMealExpenses - totalMealCosts >= 0){
        foodDebtToCompany = 0;
    } else{
        foodDebtToCompany = totalMealCosts - maximumMealExpenses;
    }

    return foodDebtToCompany;
}



float getSavedFoodMoney(){
    getMaxMealExpenses();

    if(maximumMealExpenses - totalMealCosts > 0){
        savedFoodMoney = maximumMealExpenses - totalMealCosts;
    } else{
        savedFoodMoney = 0;
    }

    return savedFoodMoney;
}



//DELETE MAIN
int main(){
    tripDuration();
    tripDeparture();
    tripArrival();
    
    getTotalMealCosts();
    printf("TotalMealCosts: %f\n", totalMealCosts);
    getMaxMealExpenses();
    printf("Max meals: %f\n", maximumMealExpenses);
    getFoodDebtToCompany();
    printf("Food debt: %f\n", foodDebtToCompany);
    getSavedFoodMoney();
    printf("SavedFoodMoney: %f\n", savedFoodMoney);
    
    //getMaxMealExpenses();
}