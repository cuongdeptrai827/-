#include<stdio.h>
// not done.
enum transport{car,truck,bus,vans};
struct square {
    float side;
};
float tinhChuViHinhVuong(struct square hv) {
    return 4 * hv.side;
}
int main() {
    enum transport type;
    type= bus;
    printf("Chi so cua bus la %d\n", type );


    struct square hv = {2.0};

    printf("Chu vi cua hinh vuong la: %.2f\n", tinhChuViHinhVuong(hv));

    return 0;
}




