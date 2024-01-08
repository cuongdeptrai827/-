#include <stdio.h>
#include <string.h>

//done !

// Concatenate two strings
void concatenateStrings(char str1[], char str2[]) {
    strcat(str1, str2);
    printf("Concatenated string : %s\n", str1);
}

// Compare n first symbols of two strings
int compareFirstNChars(char str1[], char str2[], int n) {
    return strncmp(str1, str2, n);
}

void search(char str1[], char str2[]) {
    char *ptr;
    ptr = strpbrk(str1, str2);

    if (ptr != NULL) {
        int position = ptr - str1; // tính vị trí của ký tự trong chuỗi thứ 1
        printf("Ky tu tu chuoi thu hai duoc tim thay tai vi tri: %d\n", position);
    } else {
        printf("Khong tim thay ky tu tu chuoi thu hai trong chuoi thu nhat.\n");
    }
}

//Xác định độ dài của đoạn không chứa các ký tự trong chuỗi thứ hai
int lengthOfSegmentWithoutChars(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (int i = 0; i < len1; i++) {
        if (strchr(str2, str1[i]) != NULL) {
            return i; // Độ dài của đoạn không chứa các ký tự trong chuỗi thứ hai
        }
    }

    return len1; // Nếu không có ký tự nào trong chuỗi thứ hai xuất hiện trong chuỗi thứ nhất
}

int main(void) {
    char string1[100], string2[100];
    int n;

    printf("Nhap chuoi thu nhat: ");
    gets(string1);
    int length1 = strlen(string1);

    printf("Nhap chuoi thu hai: ");
    gets(string2);

    // Ques 1.
    concatenateStrings(string1, string2);

    // Ques 3.
    int length2 = strlen(string2);
    printf("Length of string 1 is : %d\n", length1);
    printf("Length of string 2 is : %d\n", length2);

    // Ques 2.
    printf("Input n symbols to compare: ");
    scanf("%d", &n);
    int result = compareFirstNChars(string1, string2, n);
    if (result == 0) {
        printf("%d first symbols of two string is the same.\n", n);
    } else {
        printf("%d first symbols of two string is different.\n", n);
    }

    // Nhiệm vụ 4
    // Nhiệm vụ 4
    char chr[2]; // Tăng độ dài của chr để chứa ký tự và null character
    printf("Input the symbol of string 1 to find in string 2: ");
    scanf("%s", chr);
    int dem;

    // Sử dụng vòng lặp for để tìm vị trí ký tự trong chuỗi
    for (int i = 0; i < length2; i++) {
        // So sánh ký tự có index i với ký tự nhập vào
        if (string2[i] == chr[0]) {
            printf("Founded symbols %c in position: %d\n", chr[0], i);
            dem++;
        }
    }
    if (dem == 0) printf("Symbol %c from string 1 is not founded in string 2",chr[0]);


    return 0;
}