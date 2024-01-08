
#include <stdio.h>
#include <math.h>

int main() {
    float a, result1, result2;

    // Input a
    printf("Input a \n");
    scanf("%f", &a);

    // Counting value of funtion 1
    float numerator1 = cos(a) + sin(a);
    float denominator1 = cos(a) - sin(a);

    // Check the denominator = 0 or not
    if (denominator1 != 0) {
        result1 = numerator1 / denominator1;
        printf("Value of function 1  is: %f\n", result1);
    } else {
        printf(" denominator = 0 -> can not determined value of function \n");
    }


    // Counting value of function 2
    float numerator2 = sin(2 * a) / cos(2 * a);
    float denominator2 = 1 / sin(2 * a);
    // check the denominator = 0 or not
    if ( denominator2 != 0 ) {
        result2 = numerator2 / denominator2;
        printf("Value of function 2  is: %f\n", result2);
    } else {
        printf(" denominator = 0 -> can not determined value of function \n");
    }
    return 0;
}

