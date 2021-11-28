#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

typedef struct node {
    char name[100];
    struct node *parent, *leftChild, *rightSibling;
} Node;

Node *createRoot(char name[])
{
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->name,name);
    node->parent = NULL;
    node->leftChild = NULL;
    node->rightSibling = NULL;
    return node;
}

Node *createNode(char name[], Node *parent)
{
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->name,name);
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

void createNode(char folder[], char file[], Node* node)
{
    if (!strcmp(folder,node->name)) { // if the folder is found
        createNode(file,node); // create file
        return;
    }
    if (node->leftChild != NULL) { // if node has children
        createNode(folder,file,node->leftChild); // visit children
    }
    if (node->rightSibling != NULL) { // for all siblings of R
        createNode(folder,file,node->rightSibling); // visit sibling
    }
}

Node* findNode(char dest[], Node* node) {
    stack<Node*> s;
    Node* curr = node;
    while (curr != NULL || !(s.empty())) { // tree traversal
        if (!strcmp(dest,curr->name)) { // if folder found
            return curr;
        }
        // adds all of the node's sibling to be checked
        for (Node* temp = curr->rightSibling; temp != NULL; temp = temp->rightSibling) {
            s.push(temp);
        }
        // adds node's child
        if (curr->leftChild != NULL) {
            s.push(curr->leftChild);
        }
        // checks next node in stack
        if (s.empty()) {
            break;
        }
        curr = s.top();
        s.pop();

    }
    return NULL;
}

void printNode(char dest[], Node* node) {
    Node* curr = findNode(dest,node);
    if (curr == NULL) {
        cout << "No Path!" << endl;
        return;
    }
    char path[1000] = "";
    for (Node* temp = curr; temp != NULL; temp  = temp->parent) {
        char t[1000];
        strcpy(t,temp->name);
        strcat(t,"/");
        strcat(t,path);
        strcpy(path,t);
    }
    int s = strlen(path)-1;
    path[s] = '\0';
    cout << path << endl;

}

int main()
{
    int n;
    char str1[100],str2[100];
    cin >> n;
    cin >> str1;
    Node *root = createRoot(str1);
    for (int i = 0; i < n; i++) {
        cin >> str1 >> str2;
        createNode(str1, str2, root);
    }
    cin >> str1;
    printNode(str1, root);
    return 0;
}