#include <stdio.h>
#include <string.h>
// not done !
// Ham tinh tong cac chu so cua 1 so tu nhien
int sumofDigits(int n){
    if ( n == 0 ) return 0;
    else {
        return n % 10 + sumofDigits(n/10);
    }
}

// Ham loai bo khoang trang thua tu chuoi

char* removeExtraspace(char *inputString){
    int length = strlen(inputString);
    int index = 0;
    int spaceCount = 0 ;
    int lastDotIndex = -1;
    int lastDot = 0;

    while (index < length){
        char currentChar = inputString[index];
        if (currentChar == ' '){
            spaceCount++;
        }
        if (spaceCount > 2){
            memmove( &inputString[index] , &inputString[index + 1], strlen(inputString) - index);
            length--;
        }
        else{
            if (currentChar =='.'){
                lastDot = 1;
                lastDotIndex = index;
            }
            else{
                lastDot = 0;
            }
            index ++;
        }
    }
    if (lastDot){
        inputString[lastDotIndex + 1] = '\0';
    }
    return inputString;
}
int main() {
    // Nhap so tu nhien tu nguoi dung
    int num;
    printf("Nhap 1 so tu nhien : ");
    scanf("%d",&num);

    // Tinh tong cac chu so cua so tu nhien
    int digitSum = sumofDigits(num);
    printf (" Tong cac chu so cua so tu nhien da cho la %d : ",digitSum);

    // Nhap chuoi
    char inputString[100];
    printf("Nhap chuoi: ");
    getchar(); // loai bo ky tu newline tu buoc truoc

    fgets(inputString,sizeof(inputString),stdin);
    inputString[strcspn(inputString,"\n")] = '\0';

    // Loai bo khoang trang thua tu chuoi va in ket qua

    char* cleanedString = removeExtraspace(inputString);
    printf("Chuoi sau khi da loai bo khoang trang la : %s \n",cleanedString);

    return 0;
}
