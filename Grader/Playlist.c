#include <stdio.h>
#include <string.h>

struct Playlist{
    char name[30];
    char song[30];

};

int main(){
    int n, a, b;
    char song[30];
    char artist[30];

    for(int i = 0;i >= 0;i++){
        printf("Enter option");
        scanf("%d",&n);

        if(n == 1){
            struct Playlist playlist[a];
            printf("Enter song name");
            scanf("%s",&song[a].song);
            printf("Enter artist name");
            scanf("%s",&artist[a].name);
        }
        else if(n == 2){
            struct Playlist playlist[a];
            printf("Enter number of song to remove");
            scanf("%d",&b);
            playlist playlist[a] = 
        }
        else if(n == 3){
            printf("all of song")
        }
        else if (n == 4){
            break;
        }
        else{
            continue;
        }

    }
}