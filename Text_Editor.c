#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void saveFile(const char* filename, const char* content) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    fputs(content, file);
    fclose(file);

    printf("File saved successfully: %s\n", filename);
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    char filename[256];
    char choice;
    char* content = NULL;
    size_t contentSize = 0;

    printf("Simple Text Editor\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. New File\n");
        printf("2. Open File\n");
        printf("3. Save File\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (content != NULL) {
                    free(content);
                    content = NULL;
                }

                printf("Enter file content (max %d characters):\n", MAX_BUFFER_SIZE);
                scanf(" %[^\n]", buffer);
                contentSize = strlen(buffer) + 1;
                content = malloc(contentSize);
                strncpy(content, buffer, contentSize);
                break;
            case '2':
                printf("Enter filename: ");
                scanf(" %[^\n]", filename);

                if (content != NULL) {
                    free(content);
                    content = NULL;
                }

                FILE* file = fopen(filename, "r");
                if (file == NULL) {
                    printf("Error opening file: %s\n", filename);
                    break;
                }

                fseek(file, 0, SEEK_END);
                contentSize = ftell(file);
                fseek(file, 0, SEEK_SET);
                content = malloc(contentSize + 1);
                fread(content, contentSize, 1, file);
                fclose(file);

                content[contentSize] = '\0';

                printf("File loaded successfully.\n");
                break;
            case '3':
                if (content == NULL) {
                    printf("No file to save.\n");
                    break;
                }

                printf("Enter filename to save: ");
                scanf(" %[^\n]", filename);
                saveFile(filename, content);
                break;
            case '0':
                printf("Exiting...\n");
                if (content != NULL) {
                    free(content);
                    content = NULL;
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

