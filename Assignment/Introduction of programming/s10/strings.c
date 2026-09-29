#include <stdio.h>
#include <string.h>

int main(void)
{
    /* Task 1 */
    char songTitle[] = "Tum Hi Ho";
    printf("Task 1: length of \"%s\" = %zu\n", songTitle, strlen(songTitle));

    /* Task 2 */
    char u1[30], u2[30];
    printf("Task 2: enter username 1: "); scanf("%29s", u1);
    printf("        enter username 2: "); scanf("%29s", u2);
    if (strcmp(u1, u2) == 0) printf("Usernames are the same\n");
    else                     printf("Usernames are different\n");

    /* Task 3 */
    char shoppingApp[20];                 /* enough space for "Flipkart" + '\0' */
    strcpy(shoppingApp, "Flipkart");
    printf("Task 3: %s\n", shoppingApp);

    /* Task 4: username = first 5 characters of the full name */
    char fullName[60], username[6];
    getchar();                            /* eat newline left by scanf */
    printf("Task 4: enter full name: ");
    fgets(fullName, sizeof fullName, stdin);
    fullName[strcspn(fullName, "\n")] = '\0';
    if (strlen(fullName) < 5) {
        strcpy(username, fullName);       /* shorter than 5: use full name */
    } else {
        strncpy(username, fullName, 5);   /* strcpy copies everything, so strncpy limits to 5 */
        username[5] = '\0';
    }
    printf("Generated username: %s\n", username);
    return 0;
}
