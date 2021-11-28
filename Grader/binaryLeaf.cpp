#include <iostream>
#include <list>
using namespace std;

int l = 0, r = 0;


typedef struct node {
    int value;
    struct node *parent, *left, *right;
} Node;

list<Node*> roots;
list<Node*>::iterator it,itN;

Node* createRoot(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    return node;
}

Node* createNode(int value,char c,Node* parent) {
    Node* node = NULL;
    for (itN = roots.begin(); itN != roots.end(); ++itN) { // for all roots
        if ((*itN)->value == value) { // if value already has a node
            node = *itN;
        }
    }
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->left = NULL;
        node->right = NULL;
        node->value = value;
    }
    node->parent = parent;
    if (c == 'L' || c == 'l') {
        parent->left = node;
    }
    if (c == 'R' || c == 'r') {
        parent->right = node;
    }
    return node;
}

bool postorder(int rootValue,int nodeValue,char c,Node* node) { // for creating nodes
    if (node == NULL) return false;
    if (node->value == rootValue) {
        createNode(nodeValue,c,node);
        return true;
    }
    bool left = postorder(rootValue,nodeValue,c,node->left);
    if (left) return true;

    bool right = postorder(rootValue,nodeValue,c,node->right);
    return right;
}

void printLeafNodes(Node *root)
{
    if (!root)
        return;
     
    if (root->left == NULL && root->right == NULL)
    {   
        Node* parent = root->parent;
        if (parent == NULL) {
            return;
        }
        if (parent->left == root) {
            l++;
        }
        if (parent->right == root) {
            r++;
        }
    }
 
    if (root->left != NULL) {
        printLeafNodes(root->left);
    }
         
    if (root->right != NULL) {
        printLeafNodes(root->right);
    }
      
}

int main()
{
    int value;
    cin >> value;
    Node* root = createRoot(value);
    roots.push_front(root);
    cin >> value;
    for (int i = 0; i < value; i++) {
        int rootValue,nodeValue;
        char c;
        bool rootCheck = false;
        cin >> rootValue >> nodeValue >> c;
        for (it = roots.begin(); it != roots.end(); ++it) { 
            rootCheck = postorder(rootValue,nodeValue,c,*it);
        }
        if (!rootCheck) { // if a tree/a node isn't added, add one and put into root list
            Node* tempRoot = createRoot(rootValue);
            roots.push_front(tempRoot);
            postorder(rootValue,nodeValue,c,tempRoot);
        }
    }
    printLeafNodes(root);
    cout << l << ' ' << r << endl;
    return 0;
}