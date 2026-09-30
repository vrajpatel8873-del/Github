/**
 * Assessment: TOPS Technologies - Software Engineering M3-A1
 * Section B - Task 4: Personal Expense Logger
 * 
 * Description:
 * Menu-driven console program to log and view personal daily expenses.
 * - struct Expense: category (char[30]), amount (float)
 * - Static/stack array holding up to 10 entries.
 * - Menu options: (1) Add Expense, (2) View All Expenses, (3) Save & Exit.
 * - On exit, writes all records to "expenses.txt" using fprintf() in format: category,amount
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 10
#define CAT_LEN 30
#define FILENAME "expenses.txt"

/* Structure definition */
struct Expense {
    char category[CAT_LEN];
    float amount;
};

/* Helper to strip newline character from fgets string */
static void stripNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}


int main(void) {
    struct Expense expenses[MAX_EXPENSES];
    int expense_count = 0;
    int choice = 0;
    char buffer[100];

    printf("===================================================\n");
    printf("              PERSONAL EXPENSE LOGGER              \n");
    printf("===================================================\n");

    while (1) {
        printf("\n------------------- MAIN MENU -------------------\n");
        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. Save & Exit\n");
        printf("-------------------------------------------------\n");
        printf("Enter your choice (1-3): ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }

        if (sscanf(buffer, "%d", &choice) != 1) {
            printf("[!] Invalid input. Please enter a number between 1 and 3.\n");
            continue;
        }

        if (choice == 1) {
            /* Option 1: Add Expense */
            if (expense_count >= MAX_EXPENSES) {
                printf("\n[WARNING]: Storage full! Maximum limit of %d expenses reached.\n", MAX_EXPENSES);
                continue;
            }

            printf("\n--- Add Expense #%d ---\n", expense_count + 1);

            /* Category */
            while (1) {
                printf("Enter Expense Category (e.g. Food, Travel, Books): ");
                if (fgets(expenses[expense_count].category, sizeof(expenses[expense_count].category), stdin) != NULL) {
                    stripNewline(expenses[expense_count].category);
                    if (strlen(expenses[expense_count].category) > 0) {
                        break;
                    }
                }
                printf("  [!] Category cannot be empty. Please enter a valid name.\n");
            }

            /* Amount */
            while (1) {
                printf("Enter Amount: ");
                if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                    if (sscanf(buffer, "%f", &expenses[expense_count].amount) == 1 &&
                        expenses[expense_count].amount > 0.0f) {
                        break;
                    }
                }
                printf("  [!] Amount must be a positive number greater than 0. Please re-enter.\n");
            }

            expense_count++;
            printf("[+] Expense recorded successfully! (Total entries: %d/%d)\n", expense_count, MAX_EXPENSES);

        } else if (choice == 2) {
            /* Option 2: View All Expenses */
            printf("\n===================================================\n");
            printf("                  EXPENSE REPORT                   \n");
            printf("===================================================\n");

            if (expense_count == 0) {
                printf("No expenses logged yet. Select option 1 to add an entry.\n");
            } else {
                float running_total = 0.0f;
                printf("+----+--------------------------------+------------+\n");
                printf("| #  | Category                       | Amount ($) |\n");
                printf("+----+--------------------------------+------------+\n");
                for (int i = 0; i < expense_count; i++) {
                    printf("| %-2d | %-30s | %10.2f |\n",
                           i + 1,
                           expenses[i].category,
                           expenses[i].amount);
                    running_total += expenses[i].amount;
                }
                printf("+----+--------------------------------+------------+\n");
                printf("|    | RUNNING TOTAL                  | %10.2f |\n", running_total);
                printf("+----+--------------------------------+------------+\n");
            }

        } else if (choice == 3) {
            /* Option 3: Save & Exit */
            printf("\nSaving records to '%s'...\n", FILENAME);

            FILE *file = fopen(FILENAME, "w");
            if (file == NULL) {
                fprintf(stderr, "[ERROR]: Could not open '%s' for writing.\n", FILENAME);
                return EXIT_FAILURE;
            }

            for (int i = 0; i < expense_count; i++) {
                fprintf(file, "%s,%.2f\n", expenses[i].category, expenses[i].amount);
            }

            fclose(file);
            printf("[SUCCESS]: %d expense record(s) successfully written to '%s'.\n", expense_count, FILENAME);
            printf("Thank you for using Personal Expense Logger. Exiting.\n");
            break;

        } else {
            printf("[!] Invalid choice (%d). Please enter 1, 2, or 3.\n", choice);
        }
    }

    return EXIT_SUCCESS;
}
