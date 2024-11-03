#include <stdio.h>
#include <stdlib.h>

// Declaration of the flag as hidden data
__attribute__((section(".hidden"))) const char hidden_flag[] = {
    'V', 0x00, 
    'O', 0x00, 
    'I', 0x00, 
    'D', 0x00, 
    '{', 0x00, 
    'D', 0x00, 
    '3', 0x00, 
    'L', 0x00, 
    'V', 0x00, 
    '3', 0x00, 
    'I', 0x00, 
    'N', 0x00, 
    'T', 0x00, 
    '0', 0x00, 
    '_', 0x00, 
    'C', 0x00, 
    '0', 0x00, 
    'D', 0x00, 
    '3', 0x00, 
    '}', 0x00, 
};

int main() {
    // The program doesn't display anything obvious
    printf("Welcome to the Chronicles of the Forgotten Time.\n");
    printf("Dig deeper to reveal what lies beneath the surface...\n");

    // Dummy instructions to fill the binary
    for (int i = 0; i < 10; i++) {
        asm volatile ("nop");
    }

    return 0;
}
