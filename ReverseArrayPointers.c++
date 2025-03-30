#include <stdio.h>

void reverse(int* arr) {
    int* start = arr;
    int* end = arr + 4; 

    while (start < end) 
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };

    printf("Array original: ");
    for (int i = 0; i < 5; i++) 
    {
        printf("%d ", *(arr + i)); // Usamos punteros en lugar de []
    }
    printf("\n");

    reverse(arr);

    printf("Array invertido: ");
    for (int i = 0; i < 5; i++) 
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    return 0;
}