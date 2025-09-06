#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STK 100

// Global stack and top pointer for simplicity
char stack[STK];
int top = -1;

// Function to push a character onto the stack
void push(char val) {
    if (top == STK - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
    }
}

// Function to pop a character from the stack
char pop() {
    if (top == -1) {
        return '\0';
    } else {
        return stack[top--];
    }
}

// Function to check the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    int i, j;
    char temp;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to convert infix to prefix
void infixToPrefix(char infix[], char prefix[]) {
    char ch, next_ch;
    int i = 0, j = 0;
    
    // Reverse the infix string
    reverseString(infix);

    // Swap '(' and ')'
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Now convert the modified infix to postfix
    i = 0;
    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            prefix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (stack[top] != '(') {
                prefix[j++] = pop();
            }
            pop(); // Pop the opening parenthesis
        } else {
            while (precedence(ch) <= precedence(stack[top])) {
                prefix[j++] = pop();
            }
            push(ch);
        }
    }
    
    while (top != -1) {
        prefix[j++] = pop();
    }
    
    prefix[j] = '\0';
    
    // Reverse the result to get the prefix expression
    reverseString(prefix);
}

int main() {
    char infix[STK], prefix[STK] = "";
    
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    infixToPrefix(infix, prefix);
    
    printf("The prefix expression is: %s\n", prefix);
    
    return 0;
}