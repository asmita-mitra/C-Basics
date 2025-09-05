#include <stdio.h>
#include <ctype.h>

#define STK 100

int stack[STK];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char postfix[]) {
    int i, op1, op2;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isdigit(ch)) {
            push(ch - '0');
        }
        else {
            op2 = pop();
            op1 = pop();

            switch (ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
    }

    return pop();
}

int main() {
    char postfix[STK];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result = %d\n", result);
    return 0;
}





