//done!
#include <stdio.h>

int isPrime(int num){
    if (num <= 1) return 0;
    for ( int i = 2; i*i <= num; i++ ){
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void printPrimes(int n){
    printf(" Prime numbers from 2 to %d is : ",n);
    for(int i = 2; i <= n; i++){
        if (isPrime(i)) printf("%d ",i);
    }
    printf("\n");
}

void simulateAccount(double initialBalance,double annualInterestRate, int numberOfMonths){
    double balance = initialBalance;
    double monthlyInterestRate = annualInterestRate / 12 / 100;

    printf(" Month      Balance \n");
    for (int month = 1; month <= numberOfMonths; month++){
        balance += balance * monthlyInterestRate;
        printf("%5d %12.2f\n",month,balance);
    }
}
int main() {
    // Yeu cau 4 : In ra cac so nguyen to
    int num;
    printf("Input an integer number : ");
    scanf("%d",&num);
    printPrimes(num);

    // Yeu cau 5 : Hien thi trang thai tai khoan ngan hang
    double initialBalance;
    double annualInterestRate;
    int numberOfMonths;

    printf("Input the money :");
    scanf("%lf",&initialBalance);
    printf("Input the interest rate (%%): ");
    scanf("%lf",&annualInterestRate);
    printf("Input months: ");
    scanf("%d",&numberOfMonths);

    simulateAccount(initialBalance,annualInterestRate,numberOfMonths);
    return 0;
}
