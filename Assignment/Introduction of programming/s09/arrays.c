#include <stdio.h>

/* Task 3 */
float averageSpend(int orders[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) sum += orders[i];
    return (float)sum / n;
}

int main(void)
{
    /* Task 1 */
    int dailySteps[7] = {6500, 8200, 7100, 10400, 5600, 12000, 9000};
    printf("Task 1:\n");
    for (int i = 0; i < 7; i++) printf("  Day %d: %d steps\n", i + 1, dailySteps[i]);

    /* Task 2 */
    int playlistRatings[3][5] = {
        {4, 5, 3, 4, 5},
        {3, 4, 4, 5, 2},
        {5, 5, 4, 4, 5}
    };
    printf("Task 2: ratings of playlist 2: ");
    for (int d = 0; d < 5; d++) printf("%d ", playlistRatings[1][d]);
    printf("\n");

    /* Task 3 */
    int zomato[7] = {250, 0, 320, 180, 450, 0, 600};
    printf("Task 3: average weekly spend = %.2f\n", averageSpend(zomato, 7));

    /* Task 4: highest score per IPL match */
    int cricketScores[4][2] = {{185, 172}, {201, 203}, {150, 149}, {168, 190}};
    printf("Task 4:\n");
    for (int m = 0; m < 4; m++) {
        int max = cricketScores[m][0];
        for (int t = 1; t < 2; t++) if (cricketScores[m][t] > max) max = cricketScores[m][t];
        printf("  Match %d highest: %d\n", m + 1, max);
    }
    return 0;
}
