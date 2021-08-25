#include <stdio.h>


void setArray(int*a, int amount){
    int array[amount];
    for(int i=0; i<amount; i++){
        array[i] = *(a+i) + *(a+i+1);
    }
    if (amount!= 0){
        setArray(&array[0], amount-1);
    }
    for(int i = 0;i<amount; i++){
        if(i == amount-1){
        printf("%d", array[i]);
        }else
        printf("%d, ", array[i]);
    }
    printf("\n");
    
}


int main(){
    int amount, num;
    scanf("%d", &amount);
    int arry[amount];
    
    for(int i = 0; i<amount; i++){
        scanf("%d", &num);
        arry[i] = num;
    }

    setArray(&arry[0], amount-1);
    for(int i = 0;i<amount; i++){
        if(i == amount-1){
        printf("%d", arry[i]);
        }else
        printf("%d, ", arry[i]);
    }


}