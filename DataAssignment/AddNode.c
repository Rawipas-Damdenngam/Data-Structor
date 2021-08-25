#include <stdio.h>

typedef struct addNode{
    struct data;
    struct addNode*next;
}addnode;

void insert(addnode*curr){
    int n = 4;    
    addnode*temp;
    if(n < s[data]){
    temp = (addnode *)malloc(sizeof(addnode));
    temp->next = curr ->next;
    curr->next = temp;
    }
}