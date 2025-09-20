#include <stdio.h>

int add(int num){
    if(num==0){
        return;
    }

    int sum1=add(num-1);
    int sum2=sum1+num;
    return sum2;

}

int main(){
    int n;
    printf("Enter number till which you want sum of:");
    scanf("%d",&n);

    printf("Sum of all numbers till %d is:%d",n,add(n));
    return 0;
}