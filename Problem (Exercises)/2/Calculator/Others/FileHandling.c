#include <stdio.h>
#include <stdlib.h>

void createFile();
void readFile();
void appendToFile();
void removeFile();


#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

int main() {
    int choice;
    
    do {
        printf("\n====== FILE HANDLING MENU ======\n");
        printf("1. Create & Write to a File\n");
        printf("2. Read File Contents\n");
        printf("3. Append Data to File\n");
        printf("4. Remove a File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer
        
        switch (choice) {
            case 1: 
                createFile(); 
                break;
            case 2:    
                readFile(); 
                break;
            case 3: 
                appendToFile(); 
                break;
            case 4: 
                removeFile(); 
                break;
            case 5: 
                printf("Exiting program...\n"); 
                break;
            default: 
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

void createFile() {
    FILE *fp;
    char fileName[50], content[100];

    printf("\nEnter file name to create: ");
    scanf("%s", fileName);
    getchar(); // Clear buffer
    
    fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }
    
    printf("Enter content to write: ");
    fgets(content, sizeof(content), stdin);
    fputs(content, fp);
    
    printf("File successfully created & written.\n");
    fclose(fp);
}

void readFile() {
    FILE *fp;
    char fileName[50], content[200];

    printf("\nEnter file name to read: ");
    scanf("%s", fileName);
    
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file! It may not exist.\n");
        return;
    }
    
    printf("File Contents (fscanf):\n");
    while (fscanf(fp, "%s", content) != EOF) {
        printf("%s", content);
    }

    rewind(fp);

    printf("\nFile Contents (fgets):\n");
    while (fgets(content, sizeof(content), fp) != NULL) {
        printf("%s", content);
    }
    
    fclose(fp);
}

void appendToFile() {
    FILE *fp;
    char fileName[50], content[100];

    printf("\nEnter file name to append to: ");
    scanf("%s", fileName);
    getchar(); // Clear buffer
    
    fp = fopen(fileName, "a");
    if (fp == NULL) {
        printf("Error opening file! It may not exist.\n");
        return;
    }
    
    printf("Enter content to append: ");
    fgets(content, sizeof(content), stdin);
    fprintf(fp, "NEW CONTENT: %s", content);
    
    printf("Content successfully appended.\n");
    fclose(fp);
}

void removeFile() {
    FILE *fp;
    char fileName[50], content[100];

    printf("\nEnter file name to remove: ");
    scanf("%s", fileName);
    getchar(); // Clear buffer
    
    if (fp == NULL) {
        printf("Error opening file! It may not exist.\n");
        return;
    }
    
    if (remove(fileName) == 0) {
        printf("File '%s' successfully deleted.\n", fileName);
    } else {
        perror("Error deleting file");
    }
}