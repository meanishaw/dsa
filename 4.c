#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff, pow;
    struct Node *next;
} Node;

Node* createNode(int c, int p) {
    Node *n = malloc(sizeof(Node));
    n->coeff = c; n->pow = p; n->next = NULL;
    return n;
}

void insert(Node **poly, int c, int p) {
    Node *n = createNode(c, p), *temp = *poly, *prev = NULL;
    while (temp && temp->pow > p) { prev = temp; temp = temp->next; }
    if (temp && temp->pow == p) { temp->coeff += c; free(n); return; }
    if (!prev) { n->next = *poly; *poly = n; } 
    else { n->next = temp; prev->next = n; }
}

Node* multiply(Node *p1, Node *p2) {
    Node *res = NULL;
    for (Node *a = p1; a; a = a->next)
        for (Node *b = p2; b; b = b->next)
            insert(&res, a->coeff * b->coeff, a->pow + b->pow);
    return res;
}

void display(Node *p) {
    while (p) {
        printf("%dx^%d", p->coeff, p->pow);
        if (p->next) printf(" + ");
        p = p->next;
    }
    printf("\n");
}

Node* readPoly() {
    Node *poly = NULL;
    int n, c, p;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coeff and power: ");
        scanf("%d %d", &c, &p);
        insert(&poly, c, p);
    }
    return poly;
}

int main() {
    printf("Enter Polynomial 1:\n");
    Node *p1 = readPoly();
    printf("Enter Polynomial 2:\n");
    Node *p2 = readPoly();
    
    printf("\nPolynomial 1: "); display(p1);
    printf("Polynomial 2: "); display(p2);

    Node *prod = multiply(p1, p2);
    printf("\nProduct: "); display(prod);
    return 0;
}
