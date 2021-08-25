#include <stdio.h>


void Tower_hanoi(int n, char start, char end, char mid ){
    if (n == 1){
        printf("move the disk 1 from %c to %c\n", start, end);
        return;
    }
    Tower_hanoi(n -1, start, mid, end); 
    printf("move the disk %d from %c to %c\n", n, start, end);
    Tower_hanoi(n-1, mid, end, start);
}
int main(){
    int num;
    char start, mid, end;
    scanf("%d", &num);
    scanf(" %c %c %c", &start, &mid, &end);
    if (num > 0 && num < 8){
        Tower_hanoi(num, start, end, mid);
    }
}