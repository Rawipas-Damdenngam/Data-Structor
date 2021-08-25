#include <stdio.h>

int main() {
    int n, number;
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        scanf("%d", &number);
        if (number > 0 && number <= 1000000){
            printf("%d = %X\n", number, number);
        }else{
            printf("%d not in a scope\n", number);
        }
    }
    return 0;
}