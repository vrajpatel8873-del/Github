/**
 * Assessment: TOPS Technologies - Software Engineering M3-A1
 * Section D - Step 2: Corrected & Debugged C Program
 * 
 * Fixes Applied over AI Original:
 * 1. Fixed Min/Max initialization bug: initialized to arr[0] after input (or derived directly from
 *    sorted indices arr[0] and arr[9]), resolving critical failures with all-positive or all-negative sets.
 * 2. Added boundary guard for identical inputs: when all values are identical (min == max), explicitly
 *    reports identical values rather than false "closer to max" or degenerate "midway".
 * 3. Floating-point comparison safety: uses EPSILON tolerance (fabsf) to prevent IEEE-754 precision bugs.
 * 4. Input validation: validates scanf return code and flushes buffer on invalid entries.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10
#define EPSILON 1e-6f

static void clearStdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* discard */
    }
}

int main(void) {
    int arr[SIZE];
    long long sum = 0;
    float mean = 0.0f;
    int min_val, max_val;

    printf("====================================================\n");
    printf("     INTEGER ARRAY ANALYSER (CORRECTED VERSION)     \n");
    printf("====================================================\n");
    printf("Please enter exactly %d integers:\n", SIZE);

    for (int i = 0; i < SIZE; i++) {
        while (1) {
            printf("Element [%d]: ", i + 1);
            if (scanf("%d", &arr[i]) == 1) {
                sum += arr[i];
                break;
            } else {
                printf("  [!] Invalid input! Please enter an integer.\n");
                clearStdin();
            }
        }
    }

    /* Bubble sort in ascending order */
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    /* Min and Max reliably determined from sorted array */
    min_val = arr[0];
    max_val = arr[SIZE - 1];
    mean = (float)sum / (float)SIZE;

    /* Display sorted array */
    printf("\nSorted Array (Ascending): ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d%s", arr[i], (i == SIZE - 1) ? "" : ", ");
    }
    printf("\n");

    /* Display statistics */
    printf("---------------- STATISTICAL SUMMARY ----------------\n");
    printf("Minimum Value : %d\n", min_val);
    printf("Maximum Value : %d\n", max_val);
    printf("Sum           : %lld\n", sum);
    printf("Arithmetic Mean: %.2f\n", mean);
    printf("-----------------------------------------------------\n");

    /* Closeness comparison with robust boundary and precision handling */
    if (min_val == max_val) {
        /* Boundary Case (a): All elements identical */
        printf("Analysis: All %d values are identical (%d). The mean equals the bounds.\n", SIZE, min_val);
    } else {
        float dist_min = mean - (float)min_val;
        float dist_max = (float)max_val - mean;
        float diff = fabsf(dist_min - dist_max);

        /* Floating-point comparison with epsilon tolerance */
        if (diff < EPSILON) {
            /* Boundary Case (c): Exactly midway */
            printf("Analysis: The mean (%.2f) is exactly midway between min (%d) and max (%d).\n",
                   mean, min_val, max_val);
        } else if (dist_min < dist_max) {
            printf("Analysis: The mean (%.2f) is closer to the minimum (%d) by %.2f units.\n",
                   mean, min_val, dist_max - dist_min);
        } else {
            printf("Analysis: The mean (%.2f) is closer to the maximum (%d) by %.2f units.\n",
                   mean, max_val, dist_min - dist_max);
        }
    }

    return EXIT_SUCCESS;
}
