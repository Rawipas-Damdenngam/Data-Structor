#include <stdio.h>

int Ackermann(int m,int n){
    if(m == 0)
        return n += 1;
    else if(m > 0 && n == 0)
       return Ackermann(m - 1, 1);
    else if(m > 0 && n > 0)
        return Ackermann(m - 1, Ackermann(m, n - 1));
}

int main(){
    printf("%d\n",Ackermann(1, 2));
}

// Ackermann(1, 2)
// = Ackermann(1, 2) = Ackermann(0,Ackermann(1, 1)) = 4
// = Ackermann(1, 1) = Ackermann(0, Ackermann(1, 0)) = 3
// = Ackermann(1, 0) = Ackermann(0, 1) = 2
// = Ackermann(0, 1) = 2