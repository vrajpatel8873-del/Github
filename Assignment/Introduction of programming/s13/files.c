#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char line[100];
    FILE *fp;

    /* Task 1: write mode (creates / overwrites) */
    fp = fopen("playlist.txt", "w");
    if (!fp) { perror("open"); return 1; }
    fprintf(fp, "Tum Hi Ho\nKesariya\nApna Bana Le\n");
    fclose(fp);

    /* Task 2: read mode */
    printf("Songs:\n");
    fp = fopen("playlist.txt", "r");
    while (fgets(line, sizeof line, fp)) printf("  %s", line);
    fclose(fp);

    /* Task 3: append mode (keeps existing songs) */
    fp = fopen("playlist.txt", "a");
    fprintf(fp, "Love Me Like You Do\nDeewangi Deewangi\n");
    fclose(fp);

    /* Task 4: only songs containing "love" (case-insensitive) */
    printf("\nSongs containing 'love':\n");
    fp = fopen("playlist.txt", "r");
    while (fgets(line, sizeof line, fp)) {
        char lower[100];
        int i;
        for (i = 0; line[i]; i++) lower[i] = tolower((unsigned char)line[i]);
        lower[i] = '\0';
        if (strstr(lower, "love")) printf("  %s", line);
    }
    fclose(fp);
    return 0;
}
