#include<stdio.h>
//done.
enum transport{car,truck,bus,vans};
struct square {
    float side;
};
float tinhChuViHinhVuong(struct square hv) {
    return 4 * hv.side;
}
union PrinterStatus {
    struct {
        unsigned int power : 1;      // Бит для состояния "готов вкл/выкл"
        unsigned int lowToner : 1;   // Бит для состояния "мало тонера вкл/выкл"
        unsigned int damagedDrum : 1;// Бит для состояния "повреждён барабан вкл/выкл"
        unsigned int noPaper : 1;    // Бит для состояния "нет бумаги вкл/выкл"
    } elements;
    unsigned int hexValue;            // Хранит введенное значение в 16-ричной системе
};

int main() {
    enum transport type;
    type = bus;
    printf("Index of bus : %d\n", type);

    struct square hv = {2.0};
    printf(" Perimeter of square : %.2f\n",tinhChuViHinhVuong(hv));

    union PrinterStatus printer;

    // Ввод числа в 16-ричной системе счисления
    printf("Enter a number in hexadecimal: ");
    scanf("%x", &printer.hexValue);
    // Output the states of the device elements
    printf("State ready on/off: %d\n", printer.elements.power);
    printf("Low Toner Status on/off: %d\n", printer.elements.lowToner);
    printf("State damaged drum on/off: %d\n", printer.elements.damagedDrum);
    printf("No paper status on/off: %d\n", printer.elements.noPaper);
    return 0;
}




