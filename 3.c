#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

typedef struct {
    int front, rear;
    char data[SIZE][20];
} QUEUE;

void send(QUEUE *q, char item[]) {
    if ((q->front == (q->rear + 1) % SIZE)) {
        printf("\nQueue full\n");
        return;
    }
    q->rear = (q->rear + 1) % SIZE;
    strcpy(q->data[q->rear], item);
    if (q->front == -1) q->front = 0;
}

char* receive(QUEUE *q) {
    if (q->front == -1) {
        printf("\nQueue empty\n");
        return NULL;
    }
    char *del = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    return del;
}

void display(QUEUE q) {
    if (q.front == -1) {
        printf("\nQueue Empty\n");
        return;
    }
    printf("\nQueue contents:\n");
    int i = q.front;
    while (1) {
        printf("%s\n", q.data[i]);
        if (i == q.rear) break;
        i = (i + 1) % SIZE;
    }
}

int main() {
    int ch;
    char item[20];
    char *del;
    QUEUE q = { .front = -1, .rear = -1 };

    for (;;) {
        printf("\n1. Send\n2. Receive\n3. Display\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        getchar();

        switch (ch) {
            case 1:
                printf("\nEnter message: ");
                fgets(item, sizeof(item), stdin);
                item[strcspn(item, "\n")] = 0; // Remove newline
                send(&q, item);
                break;

            case 2:
                del = receive(&q);
                if (del) printf("\nDeleted: %s\n", del);
                break;

            case 3:
                display(q);
                break;

            case 4:
                exit(0);
        }
    }
    return 0;
}
