#include <stdio.h>

int func(int n){
    if (n==1){
        return  2;
    }
    else{
        return func(n-1)+3;
    }
}

int main(){
    printf("%d\n",func(5));
}

// แผนภาพ
//  func(5)
//  = 3 + func(4)
//  = 3 + 3 + func(3)
//  = 3 + 3 + 3 + func(2)
//  = 3 + 3 + 3 + 3 + func(1)
//  = 3 + 3 + 3 + 3 + 2
