//A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
#include <stdio.h>
#include <string.h>

int main() {
    char code[100];
    int i, length;

    printf("Enter the code name: ");
    scanf("%s", code);

    length = strlen(code);

    printf("Mirror format: ");

    for(i = length - 1; i >= 0; i--) {
        printf("%c", code[i]);
    }

    return 0;
}

// Day 10
