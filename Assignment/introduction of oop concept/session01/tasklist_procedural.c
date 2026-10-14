#include <stdio.h>
#include <string.h>

#define MAX_TASKS 5
#define TASK_LEN 100

char tasks[MAX_TASKS][TASK_LEN];
int taskCount = 0;

void addTask(const char *title) {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full (maximum %d tasks).\n", MAX_TASKS);
        return;
    }
    snprintf(tasks[taskCount], TASK_LEN, "%s", title);
    taskCount++;
}

void markTaskDone(int index) {
    if (index < 0 || index >= taskCount) {
        printf("Invalid task index.\n");
        return;
    }
    strncat(tasks[index], " - DONE", TASK_LEN - strlen(tasks[index]) - 1);
}

void showTasks(void) {
    if (taskCount == 0) {
        puts("No tasks yet.");
        return;
    }
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

int main(void) {
    addTask("Study C++");
    addTask("Practice loops");
    addTask("Submit assignment");
    puts("Initial task list:");
    showTasks();
    markTaskDone(1);
    puts("\nAfter marking task 2 as done:");
    showTasks();
    return 0;
}
