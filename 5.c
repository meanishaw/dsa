#include <stdio.h>
#include <stdlib.h>

#define SIZE 5   // Maximum queue size

int count = 0;   

struct node {
    int data;
    struct node *addr;
};
typedef struct node* NODE;

NODE insertend(NODE last, int item) {
    NODE temp;
    if (count >= SIZE) {
        printf("\nQueue full\n");
        return last;
    }
    count++;

    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;

    // First node
    if (last == NULL) {
        temp->addr = temp;
        return temp;
    } else {
        temp->addr = last->addr;
        last->addr = temp;
        return temp;
    }
}

NODE deletebegin(NODE last) {
    NODE temp;
    if (last == NULL) {
        printf("\nQueue empty\n");
        return NULL;
    }

    if (last->addr == last) {
        printf("\nElement deleted is %d\n", last->data);
        free(last);
        count--;
        return NULL;
    } 
    else {
        temp = last->addr;
        last->addr = temp->addr;
        printf("\nElement deleted is %d\n", temp->data);
        free(temp);
        count--;
        return last;
    }
}


void display(NODE last) {
    NODE temp;
    if (last == NULL) {
        printf("\nQueue is empty\n");
    } else {
        printf("\nQueue contents are:\n");
        temp = last->addr;
        while (temp != last) {
            printf("%d\t", temp->data);
            temp = temp->addr;
        }
        printf("%d\t\n", temp->data);
    }
}


int main() {
    NODE last = NULL;
    int item, ch;

    for (;;) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter data to be inserted: ");
                scanf("%d", &item);
                last = insertend(last, item);
                break;

            case 2:
                last = deletebegin(last);
                break;

            case 3:
                display(last);
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}
