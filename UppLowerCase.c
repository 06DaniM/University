#include <stdio.h>

int main() {
    char ch;

    // Ask the user to input a character
    printf("Enter a letter: ");
    scanf_s("%c", &ch);

    // Check if the character is uppercase (A-Z)
    if (ch >= 'A' && ch <= 'Z') {
        // Convert to lowercase by adding the difference between 'a' and 'A' (32)
        ch = ch + ('a' - 'A');
    }
    // Check if the character is lowercase (a-z)
    else if (ch >= 'a' && ch <= 'z') {
        // Convert to uppercase by subtracting the difference between 'a' and 'A' (32)
        ch = ch - ('a' - 'A');
    }
    else {
        printf("Invalid input, please enter an alphabet letter.\n");
        return 1;
    }

    // Output the converted letter
    printf("Converted letter: %c\n", ch);

    return 0;
}