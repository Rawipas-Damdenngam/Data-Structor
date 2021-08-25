#include <stdio.h>
#include <string.h>

struct NamePrice{
        char name[30];
        float price;
        int id;
    };


int main(){
    int n;
    float cash;
    float max = 0;
    
    char str[30];
    

    scanf("%d",&n);
   struct NamePrice nameprice[n];
    for(int i = 0;i < n;i++){
        scanf("%s %f",&str ,&nameprice[i].price);
        nameprice[i].id = i+1;
        strcpy(nameprice[i].name ,str);
    }

    scanf("%f",&cash);

    float min =nameprice[0].price;

    int posmax = 0;
    for(int i = 0;i < n;i++){
        if(max < nameprice[i].price){
            max = nameprice[i].price;
            posmax = i;
        }
    }
    
    int posmin = 0;
    for(int i = 0;i < n;i++){
        if(min >=nameprice[i].price){
            min = nameprice[i].price;
            posmin = i;
        }
    }

    printf("Max price product(s) is:\n");
    for(int i = 0; i< n;i++){
        if(nameprice[i].price == max)
        printf("    id: %03d name: %s price: %.2f Baht\n",nameprice[i].id ,nameprice[i].name ,max);
    }
    printf("Min price product(s) is:\n");
    for(int i = 0; i < n;i++){
        if(nameprice[i].price == min)
        printf("    id: %03d name: %s price: %.2f Baht\n",nameprice[i].id ,nameprice[i].name ,min);
    }
    printf("Products' price that <= %.2f Baht is:\n",cash);
        for(int i = 0;i < n;i++){
            if(nameprice[i].price <= cash){
                printf("    id: %03d name: %s price: %.2f Baht\n",nameprice[i].id ,nameprice[i].name ,nameprice[i].price);
            }
        }
    
}