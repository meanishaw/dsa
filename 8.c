#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node* createNode(char c) {
    Node* n = malloc(sizeof(Node));
    n->data = c; 
    n->left = n->right = NULL;
    return n;
}

Node* stack[100]; 
int top = -1;
void push(Node* n) { stack[++top] = n; }
Node* pop() { return stack[top--]; }

Node* buildTree(char postfix[]) {
    for (int i = 0; postfix[i]; i++) {
        if (isalnum(postfix[i])) push(createNode(postfix[i]));
        else {
            Node* n = createNode(postfix[i]);
            n->right = pop();
            n->left = pop();
            push(n);
        }
    }
    return pop();
}

void inorder(Node* root)  { if(root){ inorder(root->left); printf("%c ",root->data); inorder(root->right);} }
void preorder(Node* root) { if(root){ printf("%c ",root->data); preorder(root->left); preorder(root->right);} }
void postorder(Node* root){ if(root){ postorder(root->left); postorder(root->right); printf("%c ",root->data);} }

int main() {
    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    Node* root = buildTree(postfix);

    printf("Inorder: "); inorder(root); printf("\n");
    printf("Preorder: "); preorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");
    return 0;
}
