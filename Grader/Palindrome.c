#include <stdio.h>
#include <string.h>

int strRev(char *word){
    int count, i;
    while(word[count]!='\0'){
        count++;
    }

    char wordrev[100];
    int idex = count -1;
    for(i =0; i<count; i++){
        wordrev[i] = word[idex];
        idex--;
    }
    wordrev[i] = '\0';
    if(strcmp(word, wordrev) == 0){
        return 1;
    }
    else return 0;
}


int main(){
    int count;
    char word[100];
    scanf("%d", &count);
    for (int i=0; i < count; i++){
        scanf("%s", word);
        if (strRev(word)){
            printf("%s Is Palindrome.\n", word);
        }else{
            printf("%s Is Not Palindrome.\n", word);
        }
    }
}