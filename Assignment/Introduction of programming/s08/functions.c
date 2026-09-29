#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Task 1 */
void getUserInitials(const char *fullName, char *out)
{
    int k = 0;
    int newWord = 1;
    for (int i = 0; fullName[i] != '\0'; i++) {
        if (fullName[i] == ' ') newWord = 1;
        else if (newWord) { out[k++] = toupper((unsigned char)fullName[i]); newWord = 0; }
    }
    out[k] = '\0';
}

/* Task 2: array + count passed by pointer (arrays decay to pointers = pass by reference) */
void addToCart(char cart[][30], int *count, const char *product)
{
    strcpy(cart[*count], product);
    (*count)++;
    printf("Cart inside function: ");
    for (int i = 0; i < *count; i++) printf("%s%s", cart[i], i < *count - 1 ? ", " : "\n");
}

/* Task 3 */
void increaseFollowersByValue(int followers)      { followers += 1000; printf("  inside ByValue: %d\n", followers); }
void increaseFollowersByReference(int *followers) { *followers += 1000; printf("  inside ByReference: %d\n", *followers); }

/* Task 4: Indian digit grouping, e.g. 1599 -> ₹1,599 ; 125000 -> ₹1,25,000 */
void formatPrice(long price, char *out)
{
    char digits[32], grouped[48];
    sprintf(digits, "%ld", price);
    int len = (int)strlen(digits), g = 0;
    for (int i = 0; i < len; i++) {
        int rem = len - i - 1;              /* digits still to come after this one */
        grouped[g++] = digits[i];
        /* comma before the last 3 digits, then before every 2 digits (Indian grouping) */
        if (rem >= 3 && (rem == 3 || (rem - 3) % 2 == 0)) grouped[g++] = ',';
    }
    grouped[g] = '\0';
    sprintf(out, "₹%s", grouped);
}

/* Task 5: reusable for ANY string (product names, usernames, ...) */
void capitalizeFirst(char *s)
{
    if (s[0] != '\0') s[0] = toupper((unsigned char)s[0]);
}

int main(void)
{
    char initials[16];
    getUserInitials("virat kohli", initials);
    printf("Task 1: %s\n", initials);

    char cart[10][30];
    int count = 0;
    addToCart(cart, &count, "Mobile");
    addToCart(cart, &count, "Earbuds");
    printf("Task 2: cart outside function has %d items (change persisted)\n", count);

    int followers = 5000;
    printf("Task 3: followers = %d\n", followers);
    increaseFollowersByValue(followers);
    printf("  after ByValue: %d (unchanged)\n", followers);
    increaseFollowersByReference(&followers);
    printf("  after ByReference: %d (changed)\n", followers);

    long prices[3] = {1599, 24999, 125000};
    char buf[32];
    printf("Task 4:\n");
    for (int i = 0; i < 3; i++) { formatPrice(prices[i], buf); printf("  %s\n", buf); }

    char product[] = "wireless mouse", user[] = "vraj";
    capitalizeFirst(product); capitalizeFirst(user);
    printf("Task 5: %s | %s\n", product, user);
    return 0;
}
