#include <stdio.h>

int main(void)
{
    /* Task 1: 5x5 emoji grid */
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) printf("📷 ");
        printf("\n");
    }

    /* Task 2: right triangle of increasing numbers */
    printf("\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) printf("%d ", j);
        printf("\n");
    }

    /* Task 3: pyramid, 6 rows */
    printf("\n");
    for (int i = 1; i <= 6; i++) {
        for (int s = 1; s <= 6 - i; s++) printf(" ");
        for (int k = 1; k <= 2 * i - 1; k++) printf("*");
        printf("\n");
    }

    /* Task 4: 4x4 alternating 0/1 checkerboard */
    printf("\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) printf("%d ", (i + j) % 2);
        printf("\n");
    }

    /* Task 5: pyramid with user-defined rows */
    int rows;
    printf("\nEnter number of rows: ");
    if (scanf("%d", &rows) == 1) {
        for (int i = 1; i <= rows; i++) {
            for (int s = 1; s <= rows - i; s++) printf(" ");
            for (int k = 1; k <= 2 * i - 1; k++) printf("*");
            printf("\n");
        }
    }
    return 0;
}
