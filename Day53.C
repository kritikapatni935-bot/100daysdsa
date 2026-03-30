#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int hd;
    struct Node *left, *right;
};

struct Node* create(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = create(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = create(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = create(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

struct QNode {
    struct Node* node;
    int hd;
};

void verticalOrder(struct Node* root) {
    if (!root) return;

    struct QNode queue[1000];
    int front = 0, rear = 0;

    int map[2000][2000];
    int count[2000] = {0};

    int offset = 1000;

    queue[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        int index = hd + offset;
        map[index][count[index]++] = curr->data;

        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, hd - 1};
        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, hd + 1};
    }

    for (int i = 0; i < 2000; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}
// Day 53
