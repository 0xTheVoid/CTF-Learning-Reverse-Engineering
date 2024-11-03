#include <stdio.h>
#include <string.h>

// Main function
int main() {
    char input[50];

    printf("Welcome, adventurer. Enter the password to reveal the hidden message: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character
    input[strcspn(input, "\n")] = 0;

    if (strcmp(input, "VOID{D1sc0v3r_Th3_Unkn0wn_C0d3}") == 0) {
        printf("\nCongratulations! Here is the hidden message:\n");
        printf("\"Knowledge opens the doors to infinity.\"\n");
    } else {
        printf("\nIncorrect password. The temple remains silent...\n");
    }

    return 0;
}
