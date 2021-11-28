#include <iostream>
#include <stack>
#include <cstring>
#include <climits>
using namespace std;

int max_value = INT_MIN;

typedef struct node {
    int value;
    struct node *parent, *leftChild, *rightSibling;
} Node;

Node *createRoot(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->parent = NULL;
    node->leftChild = NULL;
    node->rightSibling = NULL;
    return node;
}

Node *createNode(int value, Node *parent)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->parent = parent; // give the node a parent (if it exists)
    node->leftChild = NULL;
    node->rightSibling = NULL;
    if (node->parent != NULL) // if the node has a parent (node != root)
    {
        if (node->parent->leftChild != NULL) // if the node's parent have children
        {
            Node *child = node->parent->leftChild; // get the parent's children
            while (child->rightSibling != NULL) // for all of the parent's children
            {
                child = child->rightSibling; // go to the last children
            }
            child->rightSibling = node; // tell the last children that they have another sibling
        }
        else // if the node's parent doesn't have children
        {
            node->parent->leftChild = node; // give it one
        }
    }
    return node; // return the monster we created
}

void createNode(int parentValue, int nodeValue, Node* node)
{
    if (parentValue == node->value) { // if the parent value is found
        createNode(nodeValue,node); // create node
        return;
    }
    if (node->leftChild != NULL) { // if node has children
        createNode(parentValue,nodeValue,node->leftChild); // visit children
    }
    if (node->rightSibling != NULL) { // for all siblings of R
        createNode(parentValue,nodeValue,node->rightSibling); // visit sibling
    }
}

int getValue(Node *node) {
    Node *child = node->leftChild;
    int value = node->value;
    for (Node *temp = child; child != NULL; child = child->rightSibling) {
        value += getValue(child);
    }
    return value;
}

void postorder(Node *R) {
    Node* child = R->leftChild;
    while(child != NULL) {
        postorder(child);
        child = child->rightSibling;
    }
    int value = getValue(R);
    if (value > max_value) {
        max_value = value;
    }
}

int main()
{
    int value;
    cin >> value;
    Node* root = createRoot(value);
    cin >> value;
    for (int i = 1; i < value; i++) {
        int m,n;
        cin >> m >> n;
        createNode(m,n,root);
    }
    postorder(root);
    cout << max_value << endl;
    return 0;
}