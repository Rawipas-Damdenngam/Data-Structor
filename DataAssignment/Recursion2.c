#include <stdio.h>

int rec(int a, int b){
    if(a == 0 || b == 0){
        return 0;
    }
    else if(a == b){
        return rec(a-1, b-1) + 2 * a -1;
    }
    else if(a > b){
        return rec(a-b, b) + rec(b, b);
    }
    else if(a < b){
        return rec(a, a) + rec(b - a, a);
    }
    else{
        return 0;
    }
}

int main(){
    printf("%d\n",rec(3, 2));
}