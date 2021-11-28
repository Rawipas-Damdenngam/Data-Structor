#include<stdio.h>
#include<stdlib.h>

int main(){
    int n1, n2;
    float f;
    float *fp;
    int *ip, *np;
    f = 10.2;
    ip = &n2;
    *ip = 20;
    fp = &f;
    n1 = n2 + *ip * (int) *fp;
    printf("%d\n",n1);
    printf("%d\n",n2);
    np = ip;
    (*np)++;
    n2++;
    printf("%d\n",n2);
    return 0;
}