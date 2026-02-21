// Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.
#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    int sum = 0;

    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate primary diagonal sum
    for(int i = 0; i < rows && i < cols; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of primary diagonal elements = %d\n", sum);

    return 0;
}


// Day 16
