/* Music Listening Logger - console app
   Concepts: loops, arrays, menu-driven UI, file I/O (persistence) */
#include <stdio.h>
#include <string.h>

#define DAYS 7
#define FILE_NAME "music_log.txt"
#define NOT_LOGGED -1

const char *dayNames[DAYS] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

/* Task 1: minutes per day for the week; NOT_LOGGED means nothing entered yet */
int minutes[DAYS];

/* discard leftover characters after bad input */
void flushInput(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* keep reading until end of line */
    }
}

void clearArray(void) { for (int i = 0; i < DAYS; i++) minutes[i] = NOT_LOGGED; }

/* Task 3: persistence - one "dayNumber minutes" line per logged day */
void saveToFile(void)
{
    FILE *fp = fopen(FILE_NAME, "w");
    if (!fp) { printf("Error: cannot write %s\n", FILE_NAME); return; }
    for (int i = 0; i < DAYS; i++)
        if (minutes[i] != NOT_LOGGED) fprintf(fp, "%d %d\n", i + 1, minutes[i]);
    fclose(fp);
}

void loadFromFile(void)
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) return;                       /* first run: no file yet */
    int day, m;
    while (fscanf(fp, "%d %d", &day, &m) == 2)
        if (day >= 1 && day <= DAYS && m >= 0) minutes[day - 1] = m;
    fclose(fp);
}

void logMinutes(void)
{
    int day, m;
    printf("Day (1=Mon ... 7=Sun): ");
    if (scanf("%d", &day) != 1 || day < 1 || day > DAYS) { printf("Invalid day.\n"); flushInput(); return; }
    printf("Minutes listened on %s: ", dayNames[day - 1]);
    if (scanf("%d", &m) != 1 || m < 0 || m > 1440) { printf("Invalid minutes (0-1440).\n"); flushInput(); return; }
    minutes[day - 1] = m;
    saveToFile();
    printf("Saved %d minutes for %s.\n", m, dayNames[day - 1]);
}

/* Task 4: report is built by READING the saved file */
void weeklyReport(void)
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) { printf("No data yet. Log some minutes first.\n"); return; }
    int day, m, count = 0, total = 0, highest = -1, highDay = 0;
    printf("\n--- Weekly Report ---\n");
    while (fscanf(fp, "%d %d", &day, &m) == 2) {
        printf("%-10s %4d min\n", dayNames[day - 1], m);
        total += m; count++;
        if (m > highest) { highest = m; highDay = day; }
    }
    fclose(fp);
    if (count == 0) { printf("No data yet. Log some minutes first.\n"); return; }
    printf("---------------------\n");
    printf("Total   : %d min\n", total);
    printf("Average : %.1f min/day (over %d logged day%s)\n", (float)total / count, count, count == 1 ? "" : "s");
    printf("Highest : %d min (%s)\n", highest, dayNames[highDay - 1]);
}

/* Task 5: reset with confirmation */
void resetData(void)
{
    char ans;
    printf("This will delete ALL weekly data. Are you sure? (y/n): ");
    scanf(" %c", &ans);
    if (ans == 'y' || ans == 'Y') {
        clearArray();                          /* clear the array */
        FILE *fp = fopen(FILE_NAME, "w");      /* "w" truncates: deletes file contents */
        if (fp) fclose(fp);
        printf("Weekly data reset.\n");
    } else {
        printf("Reset cancelled.\n");
    }
}

int main(void)
{
    int choice = 0;
    clearArray();
    loadFromFile();

    /* Task 2: menu loop until Exit */
    while (choice != 4) {
        printf("\n=== Music Listening Logger ===\n");
        printf("1. Log listening minutes\n2. View weekly summary\n3. Reset weekly data\n4. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) { flushInput(); choice = 0; }
        switch (choice) {
            case 1: logMinutes(); break;
            case 2: weeklyReport(); break;
            case 3: resetData(); break;
            case 4: printf("Goodbye!\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
