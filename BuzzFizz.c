#include <stdio.h>

int main()
{
    int x = 1;

    while (x <= 99)
    {
        if (x % 3 == 0 && x % 5 == 0)
            printf("FizzBuzz, ");
        

        else if (x == 99)
            printf("Fizz");
        

        else if (x % 3 == 0)
            printf("Fizz, ");
        

        else if (x % 5 == 0)
            printf("Buzz, ");
        
        
        else
            printf("%d, ", x);
        
        x++;
    }
    return 0;
}
