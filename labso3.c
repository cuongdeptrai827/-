#include <stdio.h>

int main() {
    // Yêu cầu 1: Nhập số nguyên từ bảng điều khiển và xuất theo hệ thống số 8
    int num1;
    printf("Nhap mot so nguyen: ");
    scanf("%o", &num1);
    printf("So da nhap trong he thong so 8: %o\n", num1);

    // Yêu cầu 2: Xuất số thập lục phân và dịch bit sang trái/phải
    int num2;
    printf("Nhap mot so nguyen: ");
    scanf("%x", &num2);
    printf("So thap luc phan: %x\n", num2);

    int shiftAmount;
    printf("Nhap so bit can dich chuyen (phai 2): ");
    scanf("%d", &shiftAmount);

    int shiftedLeft = num2 << shiftAmount;
    int shiftedRight = num2 >> shiftAmount;

    printf("Sau khi dich trai %d bit: %x\n", shiftAmount, shiftedLeft);
    printf("Sau khi dich phai %d bit: %x\n", shiftAmount, shiftedRight);

    // Yêu cầu 3: Nhập số nguyên theo hệ thống số được chỉ định và thực hiện phép toán bit
    int num3;
    int base;
    printf("Nhap mot so nguyen: ");
    scanf("%d", &num3);
    printf("Nhap he thong so cua so vua nhap (8 hoac 16): ");
    scanf("%d", &base);

    int num1InDecimal;
    if (base == 8) {
        sscanf("%o", &num1InDecimal, num3);
    } else if (base == 16) {
        sscanf("%x", &num1InDecimal, num3);
    } else {
        printf("He thong so khong hop le!\n");
        return 1;
    }

    int result = num1InDecimal ^ num3; // Phép XOR (loại trừ)
    int result2 = num1InDecimal & num3; // Phép AND

    printf("Ket qua cua phep XOR voi so da nhap: %x\n", result);
    printf("Ket qua cua phep AND voi so da nhap: %x\n", result2);

    return 0;
}
