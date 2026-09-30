/**
 * Assessment: TOPS Technologies - Software Engineering M3-A1
 * Section B - Task 1: Grade Band Checker
 * 
 * Description:
 * Console program that accepts a student's percentage score using scanf(),
 * validates that it lies within the 0 to 100 range, assigns a letter grade
 * using an if-else if cascade, and prints a motivational message for each band.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float percentage = 0.0f;

    printf("========================================\n");
    printf("        STUDENT GRADE BAND CHECKER      \n");
    printf("========================================\n");
    printf("Enter student percentage score (0 - 100): ");

    /* Input validation: verify scanf successfully reads a numeric float */
    if (scanf("%f", &percentage) != 1) {
        fprintf(stderr, "\n[ERROR]: Invalid input! Percentage must be a numeric value.\n");
        return EXIT_FAILURE;
    }

    /* Range validation: score must be between 0 and 100 inclusive */
    if (percentage < 0.0f || percentage > 100.0f) {
        fprintf(stderr, "\n[ERROR]: Score %.2f is outside valid range (0 to 100). Exiting gracefully.\n", percentage);
        return EXIT_SUCCESS;
    }

    printf("\n------------- RESULT -------------\n");
    printf("Percentage Score : %.2f%%\n", percentage);

    /* Grade evaluation using if-else if cascade */
    if (percentage >= 90.0f) {
        printf("Assigned Grade   : A\n");
        printf("Message          : A — Outstanding performance! Keep up the brilliant work.\n");
    } else if (percentage >= 75.0f) {
        printf("Assigned Grade   : B\n");
        printf("Message          : B — Good work! Keep pushing.\n");
    } else if (percentage >= 60.0f) {
        printf("Assigned Grade   : C\n");
        printf("Message          : C — Satisfactory effort! Strive for higher milestones.\n");
    } else if (percentage >= 45.0f) {
        printf("Assigned Grade   : D\n");
        printf("Message          : D — Needs improvement! Put in extra study hours.\n");
    } else {
        printf("Assigned Grade   : F\n");
        printf("Message          : F — Unsatisfactory! Don't give up; seek help and try again.\n");
    }
    printf("----------------------------------\n");

    return EXIT_SUCCESS;
}
