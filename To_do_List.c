#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 50

typedef struct {
    char description[MAX_LENGTH];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask(const char* description) {
    if (numTasks >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }

    Task newTask;
    strncpy(newTask.description, description, MAX_LENGTH);
    newTask.completed = 0;

    tasks[numTasks++] = newTask;

    printf("Task added: %s\n", description);
    printf("Your Task Index is : %d\n\n",numTasks);
}

void markTaskComplete(int index) {
    if (index < 0 || index >= numTasks) {
        printf("Invalid task index.\n");
        return;
    }

    if (tasks[index].completed) {
        printf("Task already marked as complete.\n");
    } else {
        tasks[index].completed = 1;
        printf("Task marked as complete: %s\n", tasks[index].description);
    }
}

void printTasks() {
    if (numTasks == 0) {
        printf("No tasks found.\n");
        return;
    }

    printf("Tasks:\n");

    for (int i = 0; i < numTasks; i++) {
        printf("%d. [%c] %s\n", i + 1, tasks[i].completed ? 'X' : ' ', tasks[i].description);
    }
}

int main() {
    char choice;
    char description[MAX_LENGTH];
    int index;

    do {
        printf("\nTo-Do List Application\n");
        printf("1. Add task\n");
        printf("2. Mark task complete\n");
        printf("3. Print tasks\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter task description: ");
                scanf(" %[^\n]", description);
                addTask(description);
                break;
            case '2':
                printf("Enter task index: ");
                scanf("%d", &index);
                markTaskComplete(index - 1);
                break;
            case '3':
                printTasks();
                break;
            case '0':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '0');

    return 0;
}
