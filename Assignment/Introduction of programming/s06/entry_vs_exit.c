#include <stdio.h>

int main(void)
{
    int n = 10;                       /* condition n < 5 is false from the start */

    /* Entry-controlled: condition checked BEFORE the body */
    while (n < 5) {
        printf("while body ran\n");   /* never runs */
        n++;
    }

    /* Exit-controlled: body runs first, condition checked AFTER */
    do {
        printf("do-while body ran once\n");   /* runs exactly once */
        n++;
    } while (n < 5);
    return 0;
}
/* Output: only "do-while body ran once". for/while are entry-controlled (may run 0 times),
   do-while is exit-controlled (always runs at least once). */
