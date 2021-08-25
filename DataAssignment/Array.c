#include <stdio.h>

int main(){
    int arr[3][5];
    int num, result1, result2;
    
    for(int i = 0;i < sizeof(arr);i++){
        scanf("%d",&num);
    }

    for(int i = 0;i < arr[3];i++){
        result1 += arr[i];
    }
    
    for(int i = 0;i < arr[5];i++){
        result2 += arr[i];
    }

    printf("row = %d, colum =%d", result1, result2)
}