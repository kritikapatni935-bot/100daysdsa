//Read a string and check if it is a palindrome using two-pointer comparison.
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int left, right, isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    left = 0;
    right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("It is a palindrome.\n");
    else
        printf("It is not a palindrome.\n");

    return 0;
}

// Day 11
