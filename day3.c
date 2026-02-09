// Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>

int main() {
    int n, i, k;
    int arr[100];
    int comparisons = 0;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    // Linear Search
    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Key %d found at position %d\n", k, i + 1);
    } else {
        printf("Key %d not found\n", k);
    }

    printf("Number of comparisons = %d\n", comparisons);

    return 0;
}

// Day 4
