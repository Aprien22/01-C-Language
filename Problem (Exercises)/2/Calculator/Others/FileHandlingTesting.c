#include <stdio.h>

int main() {
    system("cls");
    FILE *fp;
    char name[80];

    fp = fopen("C:\\Users\\PC\\Downloads\\Code\\File_handling_stuffs\\fhandling.txt", "r");
    if (fp == NULL) {
        printf("Error opening file! It may not exist.\n");
        return 1;
    }

    printf("\n++++++ FILE CONTENTS ++++++\n");
    while (fscanf(fp, "%s", name) == 1) {  // Corrected condition
        printf("%s\n", name);
    }

    printf("++++++ END OF FILE ++++++\n");
    fclose(fp);  // Close before renaming

    // Corrected rename function
    if (rename("C:\\Users\\PC\\Downloads\\Code\\File_handling_stuffs\\fhandling.txt", 
               "C:\\Users\\PC\\Downloads\\Code\\File_handling_stuffs\\NewFileName.txt") == 0) {
        printf("File renamed successfully.\n");
    } else {
        perror("Error renaming file");
    }

    return 0;
}
