#include <stdio.h>

struct Nitsits{
    char name[100];
    int age;
};  

int main(){
    struct Nitsits person[5];
    struct Nitsits *ptr;
   
    
    printf("Enter name and age for 5 person\n");

    for(int i = 1;i <= 5;i++){
        printf("Name and Age:");
        scanf("%s %d",&person[i].name,&person[i].age);
    }

    printf("People who over 20 years old\n");
    for(int i = 1;i <= 5;i++){
        ptr = &person[i];
        if (person[i].age > 20){
            printf("Name: %s Age: %d\n",ptr->name ,ptr->age);
        }
    }
}