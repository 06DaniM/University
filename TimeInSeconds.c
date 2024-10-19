#include <stdio.h>

int main() {
    int hour, minutes, seconds;
    int hourToSec, minToSec;

    printf("Introduce the time in the format: hour minutes seconds: \n");
    scanf_s("%d %d %d", &hour, &minutes, &seconds);

    if ((hour <= 24 && hour >= 0) && (minutes <= 60 && minutes >= 0) && (seconds <= 60 && seconds >= 0))
    {
        hourToSec = hour * 3600;
        minToSec = minutes * 60;

        int res = hourToSec + minToSec + seconds;

        printf("The number of seconds are: %d", res);
    }

    else
        printf("The numbers or the format are not correct.");

    return 0;
}
