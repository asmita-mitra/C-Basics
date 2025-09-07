#include <stdio.h>
#include <stdlib.h>

int main(){
    int count=0;
    while(1){
        printf("The loop will keep running\n");
        printf("Continue? 1.Yes 2.No\n");
        scanf("%d",&count);
        if(count==2){
            break;
        }
    }

    printf("End");

}