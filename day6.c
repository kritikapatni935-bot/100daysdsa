// Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.
#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    if (n == 0)
        return 0;

    int i = 0;  // Points to last unique element

    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    return i + 1;  // New size of unique elements
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int newSize = removeDuplicates(arr, n);

    printf("Unique elements:\n");
    for (int i = 0; i <

// Day 7
