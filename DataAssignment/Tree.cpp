#include <iostream>
#include <cstring>
using namespace std;

typedef struct node
{
    char directory[200];
    int size;
    struct node *parent, *leftChild, *rightSibling;
} Node;

Node *createRoot(char directory[], int size)
{
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->directory,directory);
    node->size = size;
    node->parent = NULL;
    node->leftChild = NULL;
    node->rightSibling = NULL;
    return node;
}

Node *createNode(char directory[], int size, Node *parent)
{
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->directory,directory);
    node->size = size;
    node->parent = parent;
    node->leftChild = NULL;
    node->rightSibling = NULL;
    if (node->parent != NULL) 
    {
        if (node->parent->leftChild != NULL) 
        {
            Node *child = node->parent->leftChild; 
            while (child->rightSibling != NULL) 
            {
                child = child->rightSibling; 
            }
            child->rightSibling = node; 
        }
        else 
        {
            node->parent->leftChild = node;
        }
    }
    return node;
}

void getDirectory(Node *node, char directory[]) {
    for (Node* temp = node; temp != NULL; temp = temp->parent) {
        char t[200];
        strcpy(t,temp->directory);
        strcat(t,directory);
        strcpy(directory,t);
    }
}

int getSize(Node *node) {
    Node *child = node->leftChild;
    int size = node->size;
    for (Node *temp = child; child != NULL; child = child->rightSibling) {
        size += getSize(child);
    }
    return size;
}

void postorder(Node *R, Node *tree) {
    if (R->leftChild != NULL) {
        postorder(R->leftChild, tree);
    }
    if (R->rightSibling != NULL) { 
        postorder(R->rightSibling, tree); 
    }
    char directory[200] = "";
    int size = getSize(R);
    getDirectory(R, directory);
    cout << directory << " [" << size << "]" << endl;
}

int main()
{
    Node *root = createRoot("/user/rt/courses/",1);
    Node *cs016 = createNode("cs016/",2,root);
    Node *grades016 = createNode("grades",8,cs016);
    Node *homeworks = createNode("homeworks/",1,cs016);
    Node *hw1 = createNode("hw1",3,homeworks);
    Node *hw2 = createNode("hw2",2,homeworks);
    Node *hw3 = createNode("hw3",4,homeworks);
    Node *programs = createNode("programs/",1,cs016);
    Node *pr1 = createNode("pr1",57,programs);
    Node *pr2 = createNode("pr2",97,programs);
    Node *pr3 = createNode("pr3",74,programs);
    Node *cs252 = createNode("cs252/",1,root);
    Node *projects = createNode("projects/",1,cs252);
    Node *papers = createNode("papers/",1,projects);
    Node *buylow = createNode("buylow",26,papers);
    Node *sellhigh = createNode("sellhigh",55,papers);
    Node *demos = createNode("demos/",1,projects);
    Node *market = createNode("market",4786,demos);
    Node *grades252 = createNode("grades",3,cs252);
    postorder(root,root);
}