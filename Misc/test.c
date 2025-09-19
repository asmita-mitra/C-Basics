#include <stdio.h>
#include <stdlib.h>

void pri(char some[]){
    printf("Hello %s",some);
}

int main(){
    char name[5];
    scanf("%s",name);
    pri(name);
}