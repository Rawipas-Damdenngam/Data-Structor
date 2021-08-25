#include <stdio.h>

double saving_ac(double total, double interest, int years){
    if (years <= 0){
        return total;
    }else {
        return saving_ac((total * (1+interest/100)), interest, years -1);
    }
}

int main(){
    double balance, interest;
    int years;
    scanf("%lf", &balance);
    scanf("%lf", &interest);
    scanf("%d", &years);
    if (balance >= 0 && interest >= 0 && years >= 0 ){
        printf("%.2lf", saving_ac(balance, interest, years));
    }
}