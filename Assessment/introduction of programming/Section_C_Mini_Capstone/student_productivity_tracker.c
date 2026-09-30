/**
 * Assessment: TOPS Technologies - Software Engineering M3-A1
 * Section C - Mini Capstone Project: Student Productivity Tracker
 * 
 * Objective:
 * Console-based Student Productivity Tracker that logs daily study hours
 * across subjects for a full week (7 days).
 * Combines arrays, structures, functions, and file handling from Module 3.
 * 
 * Requirements:
 * - Menu-driven: (1) Log Today's Study Hours, (2) View Weekly Report, (3) Save & Exit
 * - struct StudyLog { char subject[40]; float hours[7]; } with at least 3 subjects
 * - Function to calculate & display weekly total hours and daily average for each subject
 * - Simple text-based progress chart with filled dots (•) per hour studied (truncated to int)
 * - On exit, saves all records to "productivity_log.txt" using fprintf() as comma-separated lines:
 *   subject,d1,d2,d3,d4,d5,d6,d7
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SUBJECTS 3
#define DAYS_COUNT 7
#define FILENAME "productivity_log.txt"

/* Structure definition as specified */
struct StudyLog {
    char subject[40];
    float hours[7];
};

/* Day names for user-friendly display */
static const char *DAY_NAMES[DAYS_COUNT] = {
    "Mon (Day 1)", "Tue (Day 2)", "Wed (Day 3)",
    "Thu (Day 4)", "Fri (Day 5)", "Sat (Day 6)", "Sun (Day 7)"
};

/* Function prototypes */
void displayWeeklyReport(const struct StudyLog logs[], int n);
void displayProgressChart(const struct StudyLog logs[], int n);
int saveToFile(const struct StudyLog logs[], int n, const char *filepath);

int main(void) {
    /* Initialize 3 subject records */
    struct StudyLog logs[NUM_SUBJECTS] = {
        {"Mathematics",         {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}},
        {"C Programming",       {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}},
        {"Computer Networks",   {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}
    };

    char input_buffer[128];
    int choice = 0;

    printf("=================================================================\n");
    printf("           STUDENT PRODUCTIVITY TRACKER - CAPSTONE               \n");
    printf("=================================================================\n");

    while (1) {
        printf("\n=========================== MAIN MENU ===========================\n");
        printf(" 1. Log Study Hours for a Day\n");
        printf(" 2. View Weekly Report & Visual Progress Chart\n");
        printf(" 3. Save & Exit\n");
        printf("=================================================================\n");
        printf("Enter your choice (1-3): ");

        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
            break;
        }

        if (sscanf(input_buffer, "%d", &choice) != 1) {
            printf("[!] Invalid input. Please enter a valid menu number (1-3).\n");
            continue;
        }

        if (choice == 1) {
            /* Option 1: Log Study Hours */
            int day_choice = 0;
            printf("\n--- Select Day to Log Hours ---\n");
            for (int d = 0; d < DAYS_COUNT; d++) {
                printf("  %d. %s\n", d + 1, DAY_NAMES[d]);
            }
            
            while (1) {
                printf("Enter Day Number (1-7): ");
                if (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL) {
                    if (sscanf(input_buffer, "%d", &day_choice) == 1 &&
                        day_choice >= 1 && day_choice <= DAYS_COUNT) {
                        break;
                    }
                }
                printf("  [!] Please enter an integer from 1 to 7.\n");
            }

            int day_idx = day_choice - 1;
            printf("\nLogging study hours for %s:\n", DAY_NAMES[day_idx]);

            for (int s = 0; s < NUM_SUBJECTS; s++) {
                float val = 0.0f;
                while (1) {
                    printf("  -> %-18s (Current: %.2f hrs) | Enter new hours (0-24): ",
                           logs[s].subject, logs[s].hours[day_idx]);
                    if (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL) {
                        if (sscanf(input_buffer, "%f", &val) == 1 && val >= 0.0f && val <= 24.0f) {
                            logs[s].hours[day_idx] = val;
                            break;
                        }
                    }
                    printf("     [!] Hours must be a numeric value between 0.0 and 24.0.\n");
                }
            }
            printf("[+] Hours successfully recorded for %s!\n", DAY_NAMES[day_idx]);

        } else if (choice == 2) {
            /* Option 2: View Weekly Report & Progress Chart */
            displayWeeklyReport(logs, NUM_SUBJECTS);
            displayProgressChart(logs, NUM_SUBJECTS);

        } else if (choice == 3) {
            /* Option 3: Save & Exit */
            printf("\nSaving productivity data to '%s'...\n", FILENAME);
            if (saveToFile(logs, NUM_SUBJECTS, FILENAME) == 0) {
                printf("[SUCCESS]: All records successfully saved to '%s'.\n", FILENAME);
            } else {
                fprintf(stderr, "[ERROR]: Failed to write to file '%s'.\n", FILENAME);
            }
            printf("Exiting Student Productivity Tracker. Keep up the high productivity!\n");
            break;

        } else {
            printf("[!] Invalid choice (%d). Please choose 1, 2, or 3.\n", choice);
        }
    }

    return EXIT_SUCCESS;
}

/**
 * Calculates and displays the weekly total hours and daily average for each subject
 */
void displayWeeklyReport(const struct StudyLog logs[], int n) {
    printf("\n=================================================================\n");
    printf("                  WEEKLY SUBJECT STUDY REPORT                    \n");
    printf("=================================================================\n");
    printf("+----+--------------------+--------------------+----------------+\n");
    printf("| #  | Subject Name       | Total Weekly Hours | Daily Average  |\n");
    printf("+----+--------------------+--------------------+----------------+\n");

    float grand_total = 0.0f;

    for (int i = 0; i < n; i++) {
        float subject_total = 0.0f;
        for (int d = 0; d < DAYS_COUNT; d++) {
            subject_total += logs[i].hours[d];
        }
        float daily_avg = subject_total / (float)DAYS_COUNT;
        grand_total += subject_total;

        printf("| %-2d | %-18s | %14.2f hrs | %10.2f hrs |\n",
               i + 1, logs[i].subject, subject_total, daily_avg);
    }

    printf("+----+--------------------+--------------------+----------------+\n");
    printf("|    | OVERALL TOTAL      | %14.2f hrs | %10.2f hrs |\n",
           grand_total, grand_total / (float)(n * DAYS_COUNT));
    printf("+----+--------------------+--------------------+----------------+\n");
}

/**
 * Displays a text-based progress chart printing one filled dot (•) per hour studied
 */
void displayProgressChart(const struct StudyLog logs[], int n) {
    printf("\n=================================================================\n");
    printf("           DAILY PROGRESS CHART (• = 1 Hour Studied)             \n");
    printf("=================================================================\n");

    for (int i = 0; i < n; i++) {
        printf("\nSubject: %s\n", logs[i].subject);
        printf("-----------------------------------------------------------------\n");
        for (int d = 0; d < DAYS_COUNT; d++) {
            int dots = (int)logs[i].hours[d]; /* truncated to nearest integer */
            printf("  %s [%4.1f hrs]: ", DAY_NAMES[d], logs[i].hours[d]);
            if (dots == 0) {
                printf("(no study)");
            } else {
                for (int dot = 0; dot < dots; dot++) {
                    /* Print UTF-8 filled dot character '•' */
                    printf("• ");
                }
            }
            printf("\n");
        }
    }
    printf("=================================================================\n");
}

/**
 * Saves all records to file using fprintf() with one comma-separated line per subject:
 * subject,d1,d2,d3,d4,d5,d6,d7
 */
int saveToFile(const struct StudyLog logs[], int n, const char *filepath) {
    FILE *fp = fopen(filepath, "w");
    if (fp == NULL) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f\n",
                logs[i].subject,
                logs[i].hours[0], logs[i].hours[1], logs[i].hours[2],
                logs[i].hours[3], logs[i].hours[4], logs[i].hours[5],
                logs[i].hours[6]);
    }

    fclose(fp);
    return 0;
}

