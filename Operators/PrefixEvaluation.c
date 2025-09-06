#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define STK 100

int stack[STK];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int evaluatePrefix(char prefix[]) {
    int i, op1, op2;
    char ch;
    int len = strlen(prefix);

    // Scan the prefix expression from right to left
    for (i = len - 1; i >= 0; i--) {
        ch = prefix[i];

        if (isdigit(ch)) {
            // If the character is a digit, convert it to an integer and push it onto the stack
            push(ch - '0');
        } else {
            // If the character is an operator
            // Pop the two operands from the stack
            op1 = pop();
            op2 = pop();

            // Perform the operation and push the result back onto the stack
            switch (ch) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
            }
        }
    }
    
    // The final result is the only element left on the stack
    return pop();
}

int main() {
    char prefix[STK];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);
    int result = evaluatePrefix(prefix);
    printf("Result = %d\n", result);
    return 0;
}