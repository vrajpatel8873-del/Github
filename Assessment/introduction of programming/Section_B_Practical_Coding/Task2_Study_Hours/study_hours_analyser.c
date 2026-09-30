/**
 * Assessment: TOPS Technologies - Software Engineering M3-A1
 * Section B - Task 2: Weekly Study Hours Analyser
 * 
 * Description:
 * Records daily study hours for 7 days in a float array using a for loop.
 * Rejects and re-prompts for any day entry outside [0, 24].
 * Calculates and displays the weekly total, daily average, and highest study day.
 * Displays a visual bar chart with one asterisk (*) per truncated study hour.
 */

#include <stdio.h>
#include <stdlib.h>

#define DAYS_IN_WEEK 7

/* Utility function to clear invalid characters from stdin buffer */
static void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* discard */
    }
}

int main(void) {
    float study_hours[DAYS_IN_WEEK];
    float total_hours = 0.0f;
    float daily_average = 0.0f;
    int max_day_index = 0;
    float max_hours = 0.0f;

    printf("====================================================\n");
    printf("            WEEKLY STUDY HOURS ANALYSER            \n");
    printf("====================================================\n");
    printf("Please enter the study hours for each of the 7 days.\n");
    printf("(Valid range: 0.0 to 24.0 hours per day)\n\n");

    /* For loop to accept 7 daily readings with validation and re-prompting */
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        float input_val = 0.0f;
        while (1) {
            printf("Day %d study hours: ", i + 1);
            if (scanf("%f", &input_val) != 1) {
                printf("  [!] Invalid numeric format. Please enter a valid number.\n");
                clearInputBuffer();
                continue;
            }

            /* Reject negative or greater than 24 hours */
            if (input_val < 0.0f || input_val > 24.0f) {
                printf("  [!] Out of range! Hours must be between 0 and 24. Please re-enter.\n");
                continue;
            }

            /* Valid entry accepted */
            study_hours[i] = input_val;
            break;
        }
        total_hours += study_hours[i];
    }

    /* Compute daily average */
    daily_average = total_hours / (float)DAYS_IN_WEEK;

    /* Identify day with highest study hours */
    max_hours = study_hours[0];
    max_day_index = 0;
    for (int i = 1; i < DAYS_IN_WEEK; i++) {
        if (study_hours[i] > max_hours) {
            max_hours = study_hours[i];
            max_day_index = i;
        }
    }

    /* Display summary */
    printf("\n====================================================\n");
    printf("                PERFORMANCE SUMMARY                 \n");
    printf("====================================================\n");
    printf("Weekly Total Study Hours : %.2f hrs\n", total_hours);
    printf("Daily Average Hours      : %.2f hrs/day\n", daily_average);
    printf("Peak Study Day           : Day %d (%.2f hrs)\n", max_day_index + 1, max_hours);

    /* Visual bar chart: one asterisk (*) per truncated hour studied */
    printf("\n---------------- VISUAL PROGRESS BAR ----------------\n");
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        int stars = (int)study_hours[i]; /* truncated to nearest integer */
        printf("Day %d (%5.2f hrs): ", i + 1, study_hours[i]);
        for (int s = 0; s < stars; s++) {
            putchar('*');
        }
        putchar('\n');
    }
    printf("-----------------------------------------------------\n");

    return EXIT_SUCCESS;
}
