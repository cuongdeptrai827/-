#include<stdio.h>
#include<malloc.h>
// done.
int main(){
    //array using pointer
    char a1[5];
    char *p = a1;
    *p = 'H';
    *(p + 1) = 'e';
    *(p + 2) = 'l';
    *(p + 3) = 'l';
    *(p + 4) = 'o';

    for (int i = 0; i <= 4; i++){
        printf("%c", *(p + i));
    }
    printf("\n");

    //aray using dynamic memory
    char *a2 = (char*)malloc(5*sizeof(char));
    a2[0] = 'H';
    a2[1] = 'e';
    a2[2] = 'l';
    a2[3] = 'l';
    a2[4] = 'o';
    for (int i = 0; i <= 4; i++){
        printf("%c", a2[i]);
    }
    printf("\n");
    free(a2);

    return 0;
}