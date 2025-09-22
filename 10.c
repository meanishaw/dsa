#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int val) {
    if (!root) return createNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

void inorder(struct Node* root) {
    if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}
void preorder(struct Node* root) {
    if (root) { printf("%d ", root->data); preorder(root->left); preorder(root->right); }
}
void postorder(struct Node* root) {
    if (root) { postorder(root->left); postorder(root->right); printf("%d ", root->data); }
}

int main() {
    struct Node* root = NULL;
    int choice, val, key;

    while (1) {
        printf("\n1.Insert 2.Search 3.Inorder 4.Preorder 5.Postorder 6.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: "); scanf("%d", &val);
                root = insert(root, val); break;
            case 2:
                printf("Enter value to search: "); scanf("%d", &key);
                if (search(root, key)) printf("%d found\n", key);
                else printf("%d not found\n", key); break;
            case 3:
                printf("Inorder: "); inorder(root); printf("\n"); break;
            case 4:
                printf("Preorder: "); preorder(root); printf("\n"); break;
            case 5:
                printf("Postorder: "); postorder(root); printf("\n"); break;
            default: exit(0);
        }
    }
}
