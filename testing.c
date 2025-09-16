#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int age;
    char course[30];
} Person;

// === Function Prototypes ===
void trim(char *str);
void displayPeople(void);
void getPopulationByGroup(void);
void addToFile(void);
void loadFromFile(void);
int getInt(const char *prompt);

// === Global Variables ===
Person people[MAX];
int count = 0;

// === Helper Functions ===
void trim(char *str) {
    int i = 0, j = 0;
    while (str[i] == ' ') i++;                // skip leading spaces
    while (str[i]) {
        str[j++] = str[i++];                  // shift rest of string forward
    }
    str[j] = '\0';
    int end = strlen(str) - 1;
    while (end >= 0 && str[end] == ' ') str[end--] = '\0'; // trim trailing spaces
}

void removeNewLine(char *str) {
    str[strcspn(str, "\n")] = '\0';           // replace newline with string terminator
}

int getInt(const char *prompt) {
    int value;
    char buf[32];
    while (1) {
        printf("%s", prompt);
        if (fgets(buf, sizeof(buf), stdin) && sscanf(buf, "%d", &value) == 1)
            return value;                     // return valid integer
        printf("Invalid input. Please enter a number.\n");
    }
}

// === Core Features ===
void displayPeople(void) {
    system("cls");
    printf("\n--- People Entered ---\n");
    printf("%-25s %-10s %-20s\n", "Name", "Age", "Course");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-25s %-10d %-20s\n", people[i].name, people[i].age, people[i].course); // print each person's info
    }
    printf("\nPress Enter to Continue... ");
    getchar();
}

void getPopulationByGroup(void) {
    system("cls");
    printf("\n--- Get Group ---\n");
    char course[50];
    printf("Which Course? ");
    fgets(course, sizeof(course), stdin);       // read course name (no spaces)
    removeNewLine(course);                      // clear newline from buffer               
                              

    printf("\nCourse: %s\n", course);
    for (int i = 0; i < count; i++) {
        if (strcmp(people[i].course, course) == 0) { // compare course names
            printf(" - %s (Age %d)\n", people[i].name, people[i].age);
        }
    }
    printf("\n\nPress Enter to Continue... ");
    getchar();
}

void addToFile(void) {
    system("cls");
    FILE *fp = fopen("people.txt", "a");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    if (size == 0) {
        fprintf(fp, "%-25s %-10s %-20s\n", "Name", "Age", "Course"); // write header if file is empty
        fprintf(fp, "--------------------------------------------------------\n");
    }

    int n;
    printf("Enter number of people to add: ");
    scanf("%d", &n);
    getchar();                                // clear newline

    for (int i = 0; i < n && count < MAX; i++) {
        printf("\nPerson #%d\n", count + 1);
        printf("Name: ");
        fgets(people[count].name, sizeof(people[count].name), stdin); // get name input
        removeNewLine(people[count].name);                            // remove newline from name

        people[count].age = getInt("Age: ");                          // get age input safely

        printf("Course: ");
        fgets(people[count].course, sizeof(people[count].course), stdin); // get course input
        removeNewLine(people[count].course);                              // remove newline from course

        fprintf(fp, "%-25s %-10d %-20s\n", people[count].name, people[count].age, people[count].course); // write to file

        count++;                                // increment count
    }

    printf("\nNew People Added!\n");
    fclose(fp);

    printf("\nPress Enter to Continue... ");
    getchar();
}

void loadFromFile(void) {
    system("cls");
    FILE *fp = fopen("people.txt", "r");
    if (fp == NULL) {
        printf("No file to load.\n");
        return;
    }

    char line[128];
    count = 0;

    fgets(line, sizeof(line), fp);             // skip header
    fgets(line, sizeof(line), fp);             // skip separator

    while (fgets(line, sizeof(line), fp) != NULL && count < MAX) {
        char name[50] = "", course[30] = "";
        int age = 0;

        if (sscanf(line, "%25c%10d%20c", name, &age, course) == 3) { // parse fixed-width columns
            name[25] = '\0';                // null-terminate name
            course[20] = '\0';              // null-terminate course
            trim(name);                     // trim spaces from name
            trim(course);                   // trim spaces from course

            strcpy(people[count].name, name);   // copy name to struct
            people[count].age = age;            // set age
            strcpy(people[count].course, course); // copy course to struct
            count++;                            // increment count
        }
        else {
            printf("Warning: Could not parse line: %s\n", line);
        }
    }
    fclose(fp);
    printf("Data loaded from people.txt\n");
    printf("\nPress Enter to Continue... ");
    getchar();
}

// === Main Menu ===
int main(void) {
    int choice;
    do {
        system("cls");
        printf("\n=== Menu ===\n");
        printf("[1] Input People (Easy)\n");
        printf("[2] Display People\n");
        printf("[3] Search People By Group\n");
        printf("[4] Load from File (Hard)\n");
        printf("[0] Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();                            // clear newline

        switch (choice) {
        case 1: addToFile(); break;
        case 2: displayPeople(); break;
        case 3: getPopulationByGroup(); break;
        case 4: loadFromFile(); break;
        }
    } while (choice != 0);

    return 0;
}