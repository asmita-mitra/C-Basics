#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define STK 100

char stack[STK];
int top=-1;

int prece(char c){
    if(c=='^') return 3;
    
    if(c=='/'||c=='*'){
        return 2;
    }

    if(c=='+'||c=='-'){
        return 1;
    }

    else
        return -1;
}

void push(char c){
    if (top==STK-1){
        printf("Stack Overflow\n");
        return;
    }

    stack[++top]=c;
}

char pop(){
    if(top==-1){
        printf("Stack Underflow!\n");
    }
    return stack[top--];
}

void intopo(char infix[], char postfix[]) {
    int i, k = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop();
        }
        else {
            while (top != -1 && prece(stack[top]) >= prece(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}


int main(){
    char infix[STK], postfix[STK];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    intopo(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
