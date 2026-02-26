//Given an array of integers, count the number of subarrays whose sum is equal to zero.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int prefixSum = 0;

    int hash[10001] = {0};  
    int offset = 5000;      
    hash[offset] = 1; 
    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(hash[prefixSum + offset] > 0) {
            count += hash[prefixSum + offset];
        }

        hash[prefixSum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}
// Day 21
