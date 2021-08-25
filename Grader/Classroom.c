#include <stdio.h>
#include <stdlib.h>

int main(){
    int n ,x ,s ,q ,row ,row2 ,finalrow;
    int z = 0;

    scanf("%d" ,&n);
    if(n < 1){
        printf("Students not enough.");
        return 0;
    }else if(n > 40){
        printf("Too many Students.");
        return 0;
    }

    row = n / 6; 
    row2 = n % 6;
    if(row2 == 0){
        row2 = 0;
    }else{
        row2 = 1;
    }
    finalrow = row + row2;

    char chairs[finalrow][6];
    for(int i = 0; i < finalrow; i++){
        for(int j = 0; j < 6; j++){
            if(z < n){
                chairs[i][j] = 'X';
            }else{
                break;
            }
        }z++;
    }

    scanf("%d",&q); 

    for(int i = 0; i < q; i++){
        scanf("%d %d",&x, &s);
        
        if(x < 0 || x > finalrow ||s < 0 || s > 6){
            continue;
        }
        chairs[x - 1][s - 1] = 'S';
    }

    z = 0;
    for(int i = 0;i < finalrow; i++){
        for(int j = 0;j < 6;j++){
            if(z < n){
                printf("%c ",chairs[i][j]);
            }else{
                break;
            }
            z++;
        }printf("\n");
    }return 0;
}