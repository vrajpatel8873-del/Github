#include <stdio.h>
#include <string.h>

int main(void)
{
    /* Task 1: IPL Fan Bot (if-else-if) */
    char team[50];
    printf("Enter your favourite IPL team: ");
    fgets(team, sizeof team, stdin);
    team[strcspn(team, "\n")] = '\0';

    if (strcmp(team, "Mumbai Indians") == 0)              printf("Go Mumbai Indians!\n");
    else if (strcmp(team, "Chennai Super Kings") == 0)    printf("Chennai Super Kings for the win!\n");
    else if (strcmp(team, "Royal Challengers Bengaluru") == 0) printf("Ee Sala Cup Namde!\n");
    else if (strcmp(team, "Gujarat Titans") == 0)         printf("Aava De! Gujarat Titans!\n");
    else                                                  printf("Team not found!\n");

    /* Task 2: Zomato food suggestion (switch) - C can't switch on strings, so map to a number first */
    char meal[20];
    int code = 0;
    printf("\nMeal time (breakfast/lunch/dinner/snack): ");
    scanf("%19s", meal);
    if (strcmp(meal, "breakfast") == 0)  code = 1;
    else if (strcmp(meal, "lunch") == 0) code = 2;
    else if (strcmp(meal, "dinner") == 0) code = 3;
    else if (strcmp(meal, "snack") == 0) code = 4;

    switch (code) {
        case 1:  printf("Try Poha or Idli Sambar!\n"); break;
        case 2:  printf("Try Paneer Butter Masala with Roti!\n"); break;
        case 3:  printf("Try Veg Biryani!\n"); break;
        case 4:  printf("Try Samosa or Vada Pav!\n"); break;
        default: printf("Try some fruits!\n");
    }

    /* Task 3: Flipkart discount (nested if) */
    float amount, pay;
    printf("\nEnter total cart amount: ");
    scanf("%f", &amount);
    if (amount > 2000) {
        pay = amount * 0.80f;  printf("20%% discount applied.\n");
    } else {
        if (amount > 1000) { pay = amount * 0.90f; printf("10%% discount applied.\n"); }
        else               { pay = amount;         printf("No discount.\n"); }
    }
    printf("Final amount to pay: %.2f\n", pay);

    /* Task 4: eligibility (independent ifs so all applicable messages print) */
    int age;
    printf("\nEnter your age: ");
    scanf("%d", &age);
    if (age >= 18) printf("Eligible for Driving License\n");
    if (age >= 21) printf("Eligible for Credit Card\n");
    if (age >= 25) printf("Eligible for Car Rental\n");
    if (age < 18)  printf("Not eligible for anything yet\n");
    return 0;
}
