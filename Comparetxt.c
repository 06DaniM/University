#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main() {
    FILE* pFile;
    FILE* pFile1;

    pFile = fopen("MyFile.txt", "r");
    pFile1 = fopen("MyFile1.txt", "r");

    if (pFile != NULL && pFile1 != NULL) 
    {
        char c;
        char s;
        int p1 = 0;
        int p2 = 0;
        bool areTheSame = true;

        fscanf(pFile, "%c", &c);
        fscanf(pFile1, "%c", &s);

        while (fscanf(pFile, "%c", &c) != EOF) 
        {
            p1++;
        }

        while (fscanf(pFile1, "%c", &s) != EOF) 
        {
            p2++;
        }

        if (p1 != p2) 
        {
            printf("Not contain the same");
        }

        else
        {
            while (feof(pFile) == 0)
            {
                fscanf(pFile, "%c", &c);
                fscanf(pFile1, "%c", &s);

                if (c == s) areTheSame = true;
                else areTheSame = false;
            }

            if (areTheSame == true) printf("Contains the same");
            else printf("Not contain the same");
        }


        fclose(pFile);  
    }
    else {
        printf("ERROR opening the file!!!!\n");
    }

    return 0;
}
