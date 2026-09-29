#include <stdio.h>

int main(void)
{
    /* Task 1: Flipkart product */
    char productName[] = "Boat Airdopes";
    float price = 1299.50f;
    double rating = 4.35;
    printf("productName (string / char[]) : %s\n", productName);
    printf("price       (float)           : %.2f\n", price);
    printf("rating      (double)          : %.2f\n", rating);

    /* Task 2: GST as a constant */
    const float GST_RATE = 18.0f;          /* cannot be changed later */
    float basePrice = 500.0f;
    float finalPrice = basePrice + basePrice * GST_RATE / 100;
    printf("\nZomato order: base %.2f + %.0f%% GST = %.2f\n", basePrice, GST_RATE, finalPrice);
    /* GST_RATE = 20;   <- compile error: assignment of read-only variable */

    /* Task 3: Spotify playlist */
    char playlistName[] = "Arijit Hits";
    int totalSongs = 40;
    float avgDuration = 4.25f;
    printf("\nMy playlist \"%s\" has %d songs with an average duration of %.2f minutes.\n",
           playlistName, totalSongs, avgDuration);
    return 0;
}
