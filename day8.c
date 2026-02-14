// Given integers a and b, compute a^b using recursion without using pow() function.
#include <stdio.h>

long long power(long long a, int b) {
    if (b == 0)
        return 1;          // Base case
    else
        return a * power(a, b - 1);
}

int main() {
    long long a;
    int b;

    printf("Enter base (a): ");
    scanf("%lld", &a);

    printf("Enter exponent (b): ");
    scanf("%d", &b);

    printf("Result: %lld\n", power(a, b));

    return 0;
}

// Day 9
