#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int num;
    struct node *next;
}Node;

typedef struct linked_list{
    int length;
    Node *head;
}NumList;

Node *newNode(){
    Node *p;
    p = (Node *) malloc(sizeof (Node));
    p->next = NULL;
    return p;
}

void initList(NumList *n){
    n->head = NULL;
}

int appendHeadList(NumList *s, Node *p){
    if(s->head == NULL){
        s->head = p;
    }else{
        p->next = s->head;
        s->head = p;
    }
}

void deleteNode(NumList *s){
    if(s->head != NULL){
        if (s->head->next == NULL){
            s->head == NULL;
        }else{
            Node *temp = newNode();
            temp = s->head;
            while(temp->next->next != NULL)
                temp = temp->next;
            temp->next = NULL;
        }
    }
}

void printNumList(NumList L){
    Node *pCurr = L.head;
    while(pCurr != NULL){
        printf("Num: %d\n", pCurr->num);
        pCurr = pCurr->next;
    }
}

int main(){
    NumList NL;
    Node *N;
    initList(&NL);
    for(int i=0; i<3; i++){
        N = newNode();
        N->num = i;
        appendHeadList(&NL, N);
    }
    deleteNode(&NL);
    printNumList(NL);
}