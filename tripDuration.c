#include "tripDuration.h"
#include "meal1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tripLength;
char departureTime[5];
char arrivalTime[5];
float roundTripCost;

int globalDepartureHours, globalDepatureMinutes;
int globalArrivalHours, globalArrivalMinutes;

int timeValidation(char time[], int timeType);

int tripDuration(){
    printf("Please input the number of days the trip lasted, including the day of departure and the day of arrival: ");
    scanf("%d", &tripLength);
    while(tripLength<1){
        printf("Error: Not a valid input! Trip duration cannot be less than 1 day.\n");
        printf("Please reenter the trip duration in days: ");
        scanf("%d", &tripLength);
    }
    return tripLength;
}

int tripDeparture(){
    printf("Please input the time of departure in military hours with the format hour:minutes \n");
    printf("Departure time: ");
    scanf("%s", departureTime);
    timeValidation(departureTime,1);
    return 0;
}

int tripArrival(){
    printf("Please input the time of arrival in military hours in the hours:minutes format.\n");
    printf("Arrival time: ");
    scanf("%s", arrivalTime);
    timeValidation(arrivalTime,2);
    return 0;
}
                
float totalAirfare(){
    printf("Please enter the total cost of the roundtrip airfare: ");
    scanf("%f", &roundTripCost);
    while(roundTripCost<0){
        printf("Error: Not a valid input! Airfare cannot be negative.\n");
        printf("Please reenter the cost of airfare: ");
        scanf("%f", &roundTripCost);
    }
    return roundTripCost;
}

int timeValidation(char time[], int timeType){
    int hours, minutes;
    char m[2] = "";
    int timeLength;
    int error = 0;

    retype:
    if(error == 1){
        scanf("%s", time);
        m[0] = 0;
        m[1] = 0;
        error = 0;
    }
    
    timeLength = strlen(time);

    hours = atoi(time);

    if(timeLength == 4){
        m[0] = time[2];
        m[1] = time[3];
    } else if(timeLength == 5){
        m[0] = time[3];
        m[1] = time[4];
    } else{
        printf("Error: Incorrect format! Please reenter the time in military hours in the hours:minutes format.\n");
        error = 1;
        goto retype;
    }

    minutes = atoi(m);
    
    if(hours < 0 || hours > 24 || minutes < 0 || minutes > 59 || (hours==24 && minutes>=0)){
        printf("Error: Invalid time range! Please reenter the time in military hours in the hours:minutes format.\n");
        error = 1;
        goto retype;
    }

    if(timeType == 1){
        globalDepartureHours = hours;
        globalDepatureMinutes = minutes;
    } else{
        globalArrivalHours = hours;
        globalArrivalMinutes = minutes;
    }

    return 0;
}