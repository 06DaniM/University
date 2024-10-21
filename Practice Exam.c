#include <stdio.h>
#include "checkTest.h"

int isPrime(int num);
void testExercise(void);

int main()
{
    // Uncomment the line below to check if it works
    testExercise();

    return 0;
}

int isPrime(int num)
{
    if (num < 2) return 0; 
    for (int i = 2; i <= num / 2; i++) 
    {
        if (num % i == 0)
            return 0; 
    }
    return 1; 
}

/* ----------------------------------------------------------------------- */
/*                     DO NOT TOUCH THE CODE BELOW                         */
/* ----------------------------------------------------------------------- */

void testExercise()
{
    printf("Test of the exercise:\n\n");

    int res1 = isPrime(1) == 0;
    int res2 = isPrime(2) == 1;
    int res3 = isPrime(100) == 0;
    int res4 = isPrime(197) == 1;
    int res5 = isPrime(525) == 0;
    int res6 = isPrime(-1) == 0;

    // To print the result of the test
    CHECK("Exercise isPrime(...)",
        res1 == 1 &&
        res2 == 1 &&
        res3 == 1 &&
        res4 == 1 &&
        res5 == 1 &&
        res6 == 1);

    printf("\n\n");
}
