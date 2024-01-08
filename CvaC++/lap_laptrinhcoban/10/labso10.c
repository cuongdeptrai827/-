#include <stdio.h>
#include <string.h>
// not done !
int sumofDigits(int n){
    if ( n == 0 ) return 0;
    else {
        return n % 10 + sumofDigits(n/10);
    }
}

// Ham loai bo khoang trang thua tu chuoi

char* removeExtraspace(char *s){
    int length = strlen(s);
    // xoa khoang trang dau chuoi
    while(s[0]==' '){
        for(int i=0;i<length;i++){
            s[i]=s[i+1];
        }
    }
    // xoa khoang trang cuoi chuoi
    while(length > 0 && s[length - 1] == ' '){
        s[--length] ='\0';
    }
    // Xóa khoảng trắng thừa giữa các từ
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            for (int j = i; s[j] != '\0'; ++j) {
                s[j] = s[j + 1];
            }
            --i;
        }
    }
    return s;
    printf("%s",s);
}

int main() {
    // Nhap so tu nhien tu nguoi dung
    int num;
    printf("Input an integer number : ");
    scanf("%d",&num);

    // Tinh tong cac chu so cua so tu nhien
    int digitSum = sumofDigits(num);
    printf (" Sum of digits %d \n",digitSum);

    // Nhap chuoi
    char str[100];
    printf("Input a string: ");
    getchar();

    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")] = '\0';

    // Loai bo khoang trang thua tu chuoi va in ket qua

    printf(" String after remove extra spaces:%s \n",removeExtraspace(str));

    return 0;
}