#include <stdio.h>
//done.
int main() {
    //Input integers from the console and output according to the 8 number system
    int num1;
    printf("Input an integer: ");
    scanf("%d", &num1);
    printf(" number in 8 system: %o\n", num1);

    //Output hexadecimal numbers and shift bits left/right
    printf("Number in hex system: %x\n", num1);

    int shiftAmount;
    printf("Input bits to shift : ");
    scanf("%d", &shiftAmount);

    int shiftedLeft = num1 << shiftAmount;
    int shiftedRight = num1 >> shiftAmount;

    printf("After shift to the left %d bit: %x\n", shiftAmount, shiftedLeft);
    printf("After shift to the right %d bit: %x\n", shiftAmount, shiftedRight);

    //Enter an integer according to the specified number system and perform bit operations
    int num2;
    printf("Input an integer : ");
    scanf("%d", &num2);
    int result = num1 ^ num2; // Phép XOR (loại trừ)

    printf("XOR result of number 1 and number 2: %d\n", result);

    return 0;
}