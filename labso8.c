#include <stdio.h>
#include <string.h>

//not done !

// Concatenate two strings
void concatenateStrings(char str1[], char str2[]) {
    strcat(str1, str2);
    printf("Chuoi sau khi concatenate: %s\n", str1);
}

// Compare n first symbols of two strings
int compareFirstNChars(char str1[], char str2[], int n) {
    return strncmp(str1, str2, n);
}

// Get the length of a string
int getStringLength(char str[]) {
    return strlen(str);
}

// Hàm thực hiện nhiệm vụ 4: Tìm kiếm trong một chuỗi các ký tự thuộc một chuỗi khác
int searchCharacters(char str1[], char str2[]) {
    if (strpbrk(str1, str2) != NULL) {
        return 1; // Tìm thấy ký tự từ chuỗi thứ hai trong chuỗi thứ nhất
    } else {
        return 0; // Không tìm thấy
    }
}

// Hàm thực hiện nhiệm vụ 5: Xác định độ dài của đoạn không chứa các ký tự trong chuỗi thứ hai
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

int main() {
    char string1[100], string2[100];
    int n;

    printf("Nhap chuoi thu nhat: ");
    gets(string1);

    printf("Nhap chuoi thu hai: ");
    gets(string2);

    // Nhiệm vụ 1
    concatenateStrings(string1, string2);

    // Nhiệm vụ 2
    printf("Nhap so ky tu muon so sanh (n): ");
    scanf("%d", &n);
    int result = compareFirstNChars(string1, string2, n);
    if (result == 0) {
        printf("N %d ky tu dau tien cua hai chuoi giong nhau.\n", n);
    } else {
        printf("%d ky tu dau tien cua hai chuoi khac nhau.\n", n);
    }

    // Nhiệm vụ 3
    char string3[100];
    gets(string3);
    int length = strlen(string3);
    printf("Do dai cua chuoi la: %d\n", length);

    // Nhiệm vụ 4
    if (searchCharacters(string1, string2)) {
        printf("Chuoi thu nhat chua ky tu tu chuoi thu hai.\n");
    } else {
        printf("Chuoi thu nhat khong chua ky tu tu chuoi thu hai.\n");
    }

    // Nhiệm vụ 5
    int segmentLength = lengthOfSegmentWithoutChars(string1, string2);
    printf("Do dai cua doan khong chua ky tu tu chuoi thu hai la: %d\n", segmentLength);

    return 0;
}


