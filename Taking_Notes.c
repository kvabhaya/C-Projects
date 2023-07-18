#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTES 100
#define MAX_LENGTH 200

typedef struct {
    char title[MAX_LENGTH];
    char content[MAX_LENGTH];
} Note;

Note notes[MAX_NOTES];
int numNotes = 0;

void addNote() {
    if (numNotes >= MAX_NOTES) {
        printf("Note limit reached. Cannot add more notes.\n");
        return;
    }

    Note newNote;

    printf("Enter note title: ");
    scanf(" %[^\n]", newNote.title);

    printf("Enter note content: ");
    scanf(" %[^\n]", newNote.content);

    notes[numNotes++] = newNote;

    printf("Note added.\n");
}

void viewNotes() {
    if (numNotes == 0) {
        printf("No notes found.\n");
        return;
    }

    printf("\n\nNotes:\n\n");

    for (int i = 0; i < numNotes; i++) {
        printf("Title: %s\n", notes[i].title);
        printf("Content: %s\n", notes[i].content);
        printf("--------------------\n");
    }
}

int main() {
    char choice;

    do {
        printf("\nNote-Taking Application\n");
        printf("1. Add note\n");
        printf("2. View notes\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addNote();
                break;
            case '2':
                viewNotes();
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

