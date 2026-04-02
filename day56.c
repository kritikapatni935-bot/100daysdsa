//Check whether a given binary tree is symmetric around its center.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int isMirror(struct Node* a, struct Node* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;
    if (a->data != b->data) return 0;
    return isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (n == 0) {
        printf("YES");
        return 0;
    }
    
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    struct Node **nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }
    
    for (int i = 0; i < n; i++) {
        if (nodes[i]) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }
    
    if (isMirror(nodes[0], nodes[0]))
        printf("YES");
    else
        printf("NO");
    
    return 0;
}
// Day 56
