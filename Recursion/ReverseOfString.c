#include <stdio.h>
#define MAX 100

void strev(char rev[], int i){
    if(rev[i]=='\0') return;

    strev(rev,i+1);
    printf("%c",rev[i]);
}

int main(){
    char str[MAX];
    printf("Enter string to reverse:");
    fgets(str,sizeof(str),stdin);

    strev(str,0);
    return 0;
}