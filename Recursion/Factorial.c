#include <stdio.h>

long long int fact(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * fact(num - 1);
    }
}

int main() {
    int n;
    printf("Enter a non-negative number to find its factorial: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error! Factorial of a negative number doesn't exist.\n");
    } else {
        printf("Factorial of %d is %lld.\n", n, fact(n));
    }

    return 0;
}