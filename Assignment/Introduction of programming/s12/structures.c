#include <stdio.h>

struct Playlist { char title[50]; char artist[50]; int duration; };
struct FoodItem { char itemName[40]; float price; float rating; };
struct Time     { int hours; int minutes; };
struct MovieShow { char movie[50]; int screen; struct Time time; };
struct Bio      { char description[80]; int age; };
struct InstaProfile { char username[30]; int followers; struct Bio bio; };

int main(void)
{
    /* Task 1 */
    struct Playlist song = {"Tum Hi Ho", "Arijit Singh", 262};
    printf("Task 1: %s by %s, %d seconds\n", song.title, song.artist, song.duration);

    /* Task 2 */
    struct FoodItem menu[3] = {
        {"Paneer Tikka", 249.0f, 4.4f},
        {"Veg Biryani", 199.0f, 4.2f},
        {"Masala Dosa", 129.0f, 4.5f}
    };
    printf("Task 2:\n");
    for (int i = 0; i < 3; i++)
        printf("  %s | Rs %.2f | %.1f stars\n", menu[i].itemName, menu[i].price, menu[i].rating);

    /* Task 3 */
    struct MovieShow show = {"Interstellar", 3, {18, 30}};
    printf("Task 3: Movie: %s, Screen: %d, Time: %02d:%02d\n",
           show.movie, show.screen, show.time.hours, show.time.minutes);

    /* Task 4 */
    struct InstaProfile me = {"vraj_patel", 1520, {"Ahmedabad | Investor | Builder", 25}};
    printf("Task 4: @%s | followers: %d | bio: %s | age: %d\n",
           me.username, me.followers, me.bio.description, me.bio.age);
    return 0;
}
