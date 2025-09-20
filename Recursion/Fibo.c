#include <stdio.h>

// Function declaration (prototype)
int fibo(int num);

int main() {
    int n;
    printf("Enter the number of terms for the Fibonacci series: ");
    scanf("%d", &n);

    // This loop calls the fibo function for each term from 0 to n-1
    for (int i = 0; i < n; i++) {
        printf("%d\t", fibo(i));
    }
    printf("\n"); // Add a newline for better formatting
    return 0;
}

// Recursive function to calculate the Fibonacci number
int fibo(int num) {
    if (num == 0) {
        return 0;
    } else if (num == 1) {
        return 1;
    } else {
        return (fibo(num - 1) + fibo(num - 2));
    }
}