//Construct a binary tree from given inorder and postorder traversal arrays.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = v;
    n->left = n->right = NULL;
    return n;
}

int search(int in[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (in[i] == val) return i;
    }
    return -1;
}

struct Node* build(int in[], int post[], int start, int end, int *pIndex) {
    if (start > end) return NULL;

    struct Node* node = newNode(post[*pIndex]);
    (*pIndex)--;

    if (start == end) return node;

    int iIndex = search(in, start, end, node->val);

    node->right = build(in, post, iIndex + 1, end, pIndex);
    node->left = build(in, post, start, iIndex - 1, pIndex);

    return node;
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int in[n], post[n];
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);

    int pIndex = n - 1;
    struct Node* root = build(in, post, 0, n - 1, &pIndex);

    preorder(root);

    return 0;
}
// Day 59
