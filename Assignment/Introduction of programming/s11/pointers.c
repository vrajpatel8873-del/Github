#include <stdio.h>

void swapPlaylistCounts(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void incrementFollowers(int *followers, int n)
{
    for (int i = 0; i < n; i++) *(followers + i) += 100;      /* pointer arithmetic */
    for (int i = 0; i < n; i++) printf("  friend %d: %d\n", i + 1, *(followers + i));
}

int main(void)
{
    /* Task 1 */
    int likes = 250;
    int *ptrLikes = &likes;
    printf("Task 1: value = %d, address in ptrLikes = %p\n", *ptrLikes, (void *)ptrLikes);

    /* Task 2 */
    int p1 = 40, p2 = 25;
    swapPlaylistCounts(&p1, &p2);
    printf("Task 2: after swap p1 = %d, p2 = %d\n", p1, p2);

    /* Task 3 */
    int orders[5] = {250, 320, 180, 450, 600};
    int *p = orders;
    printf("Task 3:\n");
    for (int i = 0; i < 5; i++, p++) printf("  %d at %p\n", *p, (void *)p);

    /* Task 4 */
    int followers[5] = {1200, 800, 450, 3000, 95};
    printf("Task 4: updated followers\n");
    incrementFollowers(followers, 5);
    return 0;
}
