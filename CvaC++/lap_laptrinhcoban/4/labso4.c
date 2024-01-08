#include <stdio.h>
//done.
int main() {
    int number;
    int minRange = 33;
    int maxRange = 55;
    // Input the integer number
    printf("Input an integer number : ");
    scanf("%d", &number);
    int isInRange = (number >= minRange) && (number <= maxRange);

    printf("%d %s \n",number, isInRange ? "in the range " : "not in the range ");

    char inputType;
    int bitPosition;
    // Order user select number system
    printf("Select decimal number system (D) or hex number system (H): ");
    scanf(" %c", &inputType);

    if (inputType == 'D' || inputType == 'd') {
        // Order user select bit position
        printf("Input the bit position need to check (0-31): ");
        scanf("%d", &bitPosition);

        // Check the value of bit position in the integer number
        int bitValue = (number >> bitPosition) & 1;
        printf("Value of bit :%d\n",bitValue);
    } else if (inputType == 'H' || inputType == 'h') {
        printf("Input the bit position need to check (0-7): ");
        scanf("%x", &bitPosition);
        // Kiểm tra giá trị của bit cụ thể trong số nguyên hex
        int bitValue = (number >> bitPosition) & 1;
        printf("Value of bit: %d\n", bitValue);
    }
    return 0;
}
