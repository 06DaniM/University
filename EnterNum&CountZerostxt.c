#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main() {
    FILE* pFile;

    int num1, num2;
    printf("Introduce one number: ");
    scanf_s("%d", &num1);
    printf("\nIntroduce another number: ");
    scanf_s("%d", &num2);

    pFile = fopen("numbers.txt", "w");
    if (pFile != NULL) {

        for (int i = num1; i <= num2; i++) {
            fprintf(pFile, "%d ", i);
        }
        fclose(pFile);
    }
    else {
        printf("Error opening file for writing.\n");
        return 1;
    }

    pFile = fopen("numbers.txt", "r");

    if (pFile != NULL) {

        int num;
        while (feof(pFile) == 0)
        {
            fscanf(pFile, "%d", &num);
            printf("%d ", num);
        }
        fclose(pFile);
    }
    else
    {
        printf("Error opening file for reading.\n");
        return 1;
    }

    return 0;
}
