/**
 * Assessment: TOPS Technologies - Software Engineering M3-A1
 * Section B - Task 3: Student Record Manager
 * 
 * Description:
 * Manages student records using C structures and functions.
 * Features:
 * - struct Student with fields: name, rollno, marks, grade.
 * - assignGrade(struct Student *s) to assign grades via pointer.
 * - Formatted tabular display of student records.
 * - printTopper(struct Student students[], int n) to identify and display the highest scorer.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 3
#define NAME_LEN 50

/* Structure definition as specified */
struct Student {
    char name[NAME_LEN];
    int rollno;
    float marks;
    char grade;
};

/**
 * Assigns grade to a student structure based on marks
 * Bands: A (>= 90), B (>= 75), C (>= 60), D (>= 45), F (< 45)
 */
void assignGrade(struct Student *s) {
    if (s == NULL) return;

    if (s->marks >= 90.0f) {
        s->grade = 'A';
    } else if (s->marks >= 75.0f) {
        s->grade = 'B';
    } else if (s->marks >= 60.0f) {
        s->grade = 'C';
    } else if (s->marks >= 45.0f) {
        s->grade = 'D';
    } else {
        s->grade = 'F';
    }
}

/**
 * Identifies and prints the name and marks of the student with highest marks
 */
void printTopper(struct Student students[], int n) {
    if (n <= 0) {
        printf("No student records available.\n");
        return;
    }

    int top_index = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].marks > students[top_index].marks) {
            top_index = i;
        }
    }

    printf("\n=======================================================\n");
    printf("                    TOP PERFORMER                      \n");
    printf("=======================================================\n");
    printf("Name       : %s\n", students[top_index].name);
    printf("Roll No    : %d\n", students[top_index].rollno);
    printf("Marks      : %.2f%%\n", students[top_index].marks);
    printf("Grade      : %c\n", students[top_index].grade);
    printf("=======================================================\n");
}

/* Helper to strip trailing newline from fgets */
static void stripNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main(void) {
    struct Student students[MAX_STUDENTS];
    char input_buffer[100];

    printf("=======================================================\n");
    printf("                STUDENT RECORD MANAGER                 \n");
    printf("=======================================================\n");
    printf("Please enter details for %d students:\n\n", MAX_STUDENTS);

    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("--- Student #%d ---\n", i + 1);

        /* Read Roll Number */
        while (1) {
            printf("Enter Roll Number: ");
            if (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL) {
                if (sscanf(input_buffer, "%d", &students[i].rollno) == 1 && students[i].rollno > 0) {
                    break;
                }
            }
            printf("  [!] Please enter a valid positive integer for roll number.\n");
        }

        /* Read Student Name */
        while (1) {
            printf("Enter Full Name  : ");
            if (fgets(students[i].name, sizeof(students[i].name), stdin) != NULL) {
                stripNewline(students[i].name);
                if (strlen(students[i].name) > 0) {
                    break;
                }
            }
            printf("  [!] Name cannot be empty. Please enter student's name.\n");
        }

        /* Read Marks (0 - 100) */
        while (1) {
            printf("Enter Marks (%%)  : ");
            if (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL) {
                if (sscanf(input_buffer, "%f", &students[i].marks) == 1 &&
                    students[i].marks >= 0.0f && students[i].marks <= 100.0f) {
                    break;
                }
            }
            printf("  [!] Marks must be a numeric value between 0.0 and 100.0.\n");
        }

        /* Call assignGrade() via pointer for each student */
        assignGrade(&students[i]);
        printf("\n");
    }

    /* Display formatted table with column headers */
    printf("\n=======================================================\n");
    printf("                  STUDENT GRADE REPORT                 \n");
    printf("=======================================================\n");
    printf("+---------+--------------------------------+--------+-------+\n");
    printf("| Roll No | Student Name                   | Marks  | Grade |\n");
    printf("+---------+--------------------------------+--------+-------+\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("| %-7d | %-30s | %6.2f |   %c   |\n",
               students[i].rollno,
               students[i].name,
               students[i].marks,
               students[i].grade);
    }
    printf("+---------+--------------------------------+--------+-------+\n");

    /* Print Topper */
    printTopper(students, MAX_STUDENTS);

    return EXIT_SUCCESS;
}
