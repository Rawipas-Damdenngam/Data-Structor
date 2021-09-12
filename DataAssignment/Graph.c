#include <stdio.h>
#include <stdlib.h>

int **createGraph(const int n){
    int **object  = malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++){
        object[i] = malloc(sizeof(int) * n);
        for (int j = 0; j<n; j++){
            object[i][j] = 0;
        }
    }
    
    return object;
}

void addEdge(int **object, int x, int y){
    object[x-1][y-1] = 1;
}

void printGraph(int **object, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j<n; j++){
            printf("%d", object[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n = 5;
    int **object = createGraph(n);

    addEdge(object, 1, 2);
    addEdge(object, 1, 4);
    addEdge(object, 2, 5);
    addEdge(object, 3, 1);
    addEdge(object, 3, 4);
    addEdge(object, 4, 5);

    printGraph(object, n);
}