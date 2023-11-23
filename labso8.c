// not done !
#include <stdio.h>
#include <string.h>

int main(){
    char firststring[100];
    char secondstring[100];

    // Nhap chuoi tu nguoi dung
    printf(" Nhap chuoi thu nhat : ");
    fgets(firststring,sizeof(firststring),stdin);
    printf("Nhap chuoi thu hai : ");
    fgets(secondstring,sizeof(secondstring),stdin);

    // Loai bo ki tu newline tu chuoi nhap
    firststring[strcspn(firststring,"/n")] = '0';
    secondstring[strcspn(secondstring,"/n")] = '0';

    //Noi hai chuoi
    char noistring[200];
    strcpy(noistring,firststring);
    strcat(noistring,firststring);
    printf("Chuoi sau khi noi la : &s \n");

    // So sanh n ki hieu dau tien cua hai chuoi
    int n;
    printf("Nhap so luong ki tu ma ban muon so sanh : ");
    scanf("%d",&n);
    if(strncmp(firststring,secondstring,n) == 0) {
        printf("Hai chuoi trung nhau %d ki tu dau tien ",n);
    }
    else printf(" Hai chuoi khong trung nhau %d ki tu dau tien ",n);

    //Xac dinh do dai cua chuoi
    printf("Do dai cua chuoi thu nhat %zu\n", strlen(firststring));
    printf("Do dai cua chuoi thu hai %zu\n", strlen(secondstring));

    //Tim kiem bat ki ki tu nao trong chuoi thu 2
    char *found = strpbrk(firststring,secondstring);
    if ( found != NULL){
        printf("Tim thay ki tu '%c' trong chuoi thu nhat \n",*found);
    }
    else printf("Khong tim thay ky tu nao trong chuoi thu nhat \n");


    // Xac dinh do dai cua doan chuoi khong chua ki tu cua chuoi thu 2
    size_t notFound = strcspn(firststring,secondstring);
    printf("Do dai cua doan chuoi khong chua ki tu cua doan chuoi thu 2 la %zu \n",notFound);

    return 0;
}


