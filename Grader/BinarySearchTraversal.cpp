#include <iostream>
using namespace std;

typedef struct node {
    int key;
    struct node *parent, *left, *right;
} Node;

Node* createNode(int key) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertNode(int key, Node* x) {
    Node *z = createNode(key);
    Node *y = NULL;   
    while (x != NULL) {
        y = x;
        if (z->key <= x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y != NULL) {
            if (z->key <= y->key)
                y->left = z;
            else
                y->right = z;
    }
}

int height(Node* node) {
    if (node == NULL){
        return -1;
    }
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight,rightHeight) + 1;
    }
}

void preorder(Node* node) {
    if (node == NULL){ return;}
    cout << node->key << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node) {
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->key << " ";
}

void inorder(Node* node) {
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

int main() {
    int key;
    Node *root = NULL;
    
    while (1) {
        cin >> key;
        if (key == 0){
            break;
        }
        if (root == NULL){
            root = createNode(key);
        }
        else{
            insertNode(key, root);
        }
    }
    if (root == NULL) {
        cout << "empty tree" << endl;
    }
    else {
        cout << "height of tree is " << height(root) << endl;
        cout << "preorder: ";
        preorder(root);
        cout << endl;
        cout << "postorder: ";
        postorder(root);
        cout << endl;
        cout << "inorder: ";
        inorder(root);
        cout << endl;
    }
}