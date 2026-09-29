#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    /* Task 1: countdown */
    for (int i = 10; i >= 1; i--) printf("%d ", i);
    printf("\nLift off!\n");

    /* Task 2: menu-driven IPL teams (while) */
    char teams[10][40] = {"Mumbai Indians", "Chennai Super Kings", "Gujarat Titans"};
    int count = 3, choice = 0;
    while (choice != 3) {
        printf("\n1) View favourite teams\n2) Add a new team\n3) Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        getchar();                                   /* eat leftover newline */
        if (choice == 1) {
            for (int i = 0; i < count; i++) printf("  %d. %s\n", i + 1, teams[i]);
        } else if (choice == 2) {
            if (count == 10) { printf("List full.\n"); continue; }
            printf("Team name: ");
            fgets(teams[count], 40, stdin);
            teams[count][strcspn(teams[count], "\n")] = '\0';
            count++;
        } else if (choice != 3) printf("Invalid choice.\n");
    }

    /* Task 3: Guess the Song (do-while) */
    const char *songs[3] = {"tum hi ho", "kesariya", "apna bana le"};
    srand((unsigned)time(NULL));
    const char *answer = songs[rand() % 3];
    char guess[50];
    printf("\nGuess the song! (hint: %zu characters)\n", strlen(answer));
    do {
        printf("Your guess: ");
        if (fgets(guess, sizeof guess, stdin) == NULL) break;   /* Ctrl+D / end of input: stop instead of looping forever */
        guess[strcspn(guess, "\n")] = '\0';
        if (strcmp(guess, answer) != 0) printf("Wrong, try again.\n");
    } while (strcmp(guess, answer) != 0);
    if (strcmp(guess, answer) == 0) printf("Correct! It was \"%s\".\n", answer);
    else printf("\nGave up. The song was \"%s\".\n", answer);
    return 0;
}
