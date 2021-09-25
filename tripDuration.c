#include "tripDuration.h"

int tripLength;
char[5] departureTime;
char[5] arrivalTime;
float roundTripCost;


int tripDuration(){
    printf("Please input the number of days the trip lasted, including the day of departure and the day of arrival: ");
    scanf("%d", tripLength);
    return tripLength;
}

int tripDeparture();
    printf("Please input the time of departure in military hours with the format hour:minutes \n");
    printf("Departure time: ");
    scanf("%s", departureTime);
    return 0;
}

int tripArrival(){
    printf("Please input the time of arrival in military hours with the format hour:minutes \n");
    printf("Arrival time: ");
    scanf("%s", arrivalTime);
    return 0;
}
                
float totalAirfare(){
    printf("Please enter the total cost of the roundtrip airfare: ");
    scanf("%f", roundTripCost);
    return roundTripCost;
}