#include <stdio.h>
#define  MAX_STACK_SIZE  100
#define  TRUE    1
#define  FALSE    0

typedef struct int_stack_type {
 int  item[MAX_STACK_SIZE];
 int  top;
    char    tower;
} Tower;

Tower a,b,c;
int moves = 0;

int pushStack(Tower *s, int x){
 if (s->top >= MAX_STACK_SIZE -1)
  return FALSE;
 else {
  s->top++;
  s->item[s->top] = x;
  return TRUE;
 }
}

int popStack(Tower *s, int *x) {
 if (s->top <0)
  return FALSE;
 else {
  *x = s->item[s->top];
  s->top--;
  return TRUE;
 }
}

void printStack(Tower s){
 int i;
    printf("tower %c: ", s.tower);
 for (i=0; i<=s.top; i++)
  printf("%d ", s.item[i]);
 printf("\n");
}

void printTower() {
    printStack(a);
    printStack(b);
    printStack(c);
    printf("\n");
}

void move(int n, Tower *a, Tower *b, Tower *c) {
    int x;
    if (n == 1) { 
        popStack(a, &x);
        pushStack(c, x);
        printf("move#%d: \nmove(%d,%c,%c,%c)\n\n", ++moves, n-1, a->tower, b->tower, c->tower);
        printTower();
        return;
    }
    
    move(n-1, a, c, b);
    popStack(a, &x);
    pushStack(c, x);
    printf("move#%d: \nmove(%d,%c,%c,%c)\n\n", ++moves, n-1, a->tower, b->tower, c->tower);
    printTower();
   
    move(n-1, b, a, c);
}

int main() {
    int n;
    printf("N = ");
    scanf("%d", &n);
    a.top = -1;
    b.top = -1;
    c.top = -1;
    a.tower = 'A';
    b.tower = 'B';
    c.tower = 'C';
    for (int i = n-1; i >= 0; i--) {
        pushStack(&a, i);
    }
    printf("Start\n");
    printTower(a, b, c);
    move(n, &a, &b, &c);
    return 0;
}