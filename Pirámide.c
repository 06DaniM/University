#include <stdio.h>

int main() {
    int maxfiles;
    int currentfile = 1;
    int numberperfile;

    printf("Introduce the number of files: \n");
    scanf_s("%d", &maxfiles);

    while (currentfile <= maxfiles) {

        int spaces = maxfiles - currentfile; 
        int i = 0;

        while (i < spaces)
        {
            printf(" ");
            i++;
        }

        numberperfile = 1;

        while (numberperfile <= currentfile) 
        {
            printf("%d ", numberperfile);
            numberperfile++;
        }

        printf("\n"); // Nueva línea después de cada fila
        currentfile++; // Pasar a la siguiente fila
    }

    return 0;
}
