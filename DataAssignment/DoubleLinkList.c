#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next; 
    struct node* prev;
}Node;

void append(Node** head, int new_data)
{
    Node* new_node = (Node *)malloc(sizeof(Node));
    Node* last = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
    return;
}

void printList(Node* node)
{
    Node* last;
    printf("----Forward Direction----\n");
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\n----Reverse Direction----\n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

int main(){
    Node *head = NULL;
    for(int i = 1; i <= 2; i++){
        append(&head, i);
    }
    printList(head);
}