#include <stdio.h>
#include <stdlib.h>

void heapify(int a[10], int n) {
    int i, k, v, j, flag = 0;
    for (i = n / 2; i >= 1; i--) {
        k = i;
        v = a[k];
        flag = 0;

        while (!flag && 2 * k <= n) {
            j = 2 * k;
            if (j < n) {
                if (a[j] < a[j + 1])
                    j = j + 1;
            }
            if (v >= a[j]) {
                flag = 1;
            } else {
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
    }
}

int main() {
    int n = 0, i, a[10], ch;

    for (;;) {
        printf("\n1. Create Heap");
        printf("\n2. Extract Max");
        printf("\n3. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter number of elements: ");
                scanf("%d", &n);

                printf("Enter elements:\n");
                for (i = 1; i <= n; i++)
                    scanf("%d", &a[i]);

                heapify(a, n);

                printf("\nElements after heapify:\n");
                for (i = 1; i <= n; i++)
                    printf("%d\t", a[i]);
                printf("\n");
                break;

            case 2:
                if (n >= 1) {
                    printf("\nElement deleted is %d\n", a[1]);
                    a[1] = a[n];
                    n = n - 1;
                    heapify(a, n);

                    if (n != 0) {
                        printf("\nElements after reconstructing heap:\n");
                        for (i = 1; i <= n; i++)
                            printf("%d\t", a[i]);
                        printf("\n");
                    }
                } else {
                    printf("\nNo element to delete\n");
                }
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}
