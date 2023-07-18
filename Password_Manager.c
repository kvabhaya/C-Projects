#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_ENTRIES 100

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry(const char* website, const char* username, const char* password) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Maximum number of entries reached.\n");
        return;
    }

    Entry newEntry;
    strncpy(newEntry.website, website, MAX_LENGTH);
    strncpy(newEntry.username, username, MAX_LENGTH);
    strncpy(newEntry.password, password, MAX_LENGTH);

    entries[numEntries++] = newEntry;

    printf("Entry added successfully.\n");
}

void printEntries() {
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Entries:\n");

    for (int i = 0; i < numEntries; i++) {
        printf("Website: %s\n", entries[i].website);
        printf("Username: %s\n", entries[i].username);
        printf("Password: %s\n", entries[i].password);
        printf("---------------------\n");
    }
}

int main() {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add an entry\n");
        printf("2. Print entries\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Website: ");
                scanf(" %[^\n]", website);

                printf("Username: ");
                scanf(" %[^\n]", username);

                printf("Password: ");
                scanf(" %[^\n]", password);

                addEntry(website, username, password);
                break;

            case '2':
                printEntries();
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

