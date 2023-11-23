#include<stdio.h>
//done
int main() {

    // Declare a 1-dimensional matrix
    int c[9]={12,13,14,15,16,17,18,19,20};

    // Print the matrix
    printf("Matrix in exercises 1 is : ");
    for (int i = 0;i < 9; i++) {
        printf("%d ", c[i]);
    }
   printf("\n");
  // Declare two 2x2 matrices
    int mas[2][2];
    int mas1[2][2] = {{1,1},{0,1}};
    int mas2[2][2] = {{2,0},{3,0}};

    // Calculate the product of the two matrices
    mas[0][0] = mas1[0][0] * mas2[0][0] + mas1[0][1] * mas2[1][0];
    mas[0][1] = mas1[0][0] * mas2[0][1] + mas1[0][1] * mas2[1][1];
    mas[1][0] = mas1[1][0] * mas2[0][0] + mas1[1][1] * mas2[1][0];
    mas[1][1] = mas1[1][0] * mas2[0][1] + mas1[1][1] * mas2[1][1];

    // Display the product matrix
    printf("The product of two matrix is :\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }

    return 0;
}

