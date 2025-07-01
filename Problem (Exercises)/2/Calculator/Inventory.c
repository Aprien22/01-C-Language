#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "Inventory.txt"

typedef struct
{
    char productCode[5];
    char productName[80];
    int productQuantity;

} Product;

void addProduct(Product prod);
void displayProduct(Product prod, int conts);
void updateProduct(Product prod);
void deleteProduct(Product prod);
int get_integer(const char *prompt);

int main()
{
    int input, again = 0;
    Product products;
    /*
        FILE *fp = fopen(FILENAME, "w");
        if (fp == NULL) {
            printf("Error opening file!\n");
            return 1;
        }
        fprintf(fp, "%-15s %-20s %-15s\n", "Product Code", "Product Name", "Product Quantity");
        fclose(fp);

    */
    do
    {
        system("cls");
        printf("====== INVENTORY ======\n");
        printf("Please select an option:\n");
        printf("1. Add a Product\n");
        printf("2. Display Products\n");
        printf("3. Update a Product\n");
        printf("4. Delete a Product\n");
        printf("5. Exit\n");
        input = get_integer("What would you Like to do? \n>>> ");
        while (input < 1 || input > 5)
        {
            input = get_integer("INVALID INPUT. Pleasse Try Again (1 - 5)\n");
        }

        switch (input)
        {
        case 1:
            addProduct(products);
            break;
        case 2:
            displayProduct(products, 1);
            break;
        case 3:
            updateProduct(products);
            break;
        case 4:
            deleteProduct(products);
            break;
        case 5:
            printf("Thank you for using the Program <3 <3 <3\n");
            printf("Exiting Program... \n");
            break;
        default:
            break;
        }

    } while (!(input == 5));

    return 0;
}

void addProduct(Product prod)
{
    system("cls");
    printf("===== ADD PRODUCT ===== \n");

    int input;
    char buffer[50];

    FILE *fp = fopen(FILENAME, "a");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    input = get_integer("How many product would you like to add \n>>> ");
    while (input < 0)
    {
        input = get_integer("INVALID INPUT. Please Try Again (1 - 4)\n");
    }

    for (int i = 0; i < input; i++)
    {
        printf("PRODUCT %d\n", i + 1);
        printf("PRODUCT CODE: ");

        scanf("%s", prod.productCode);
        printf("PRODUCT NAME: ");

        scanf("%s", prod.productName);
        prod.productQuantity = get_integer("PRODUCT QUANTITY: ");

        fprintf(fp, "%-15s %-20s %-15d\n", prod.productCode, prod.productName, prod.productQuantity);
        printf("\n");
    }
    printf("NEW PRODUCTS ADDED SUCCESSFULLY\n");

    printf("\nPRESS ENTER TO CONTINUE....");
    fgets(buffer, sizeof(buffer), stdin);

    fclose(fp);
}

void displayProduct(Product prod, int conts)
{
    system("cls");
    printf("===== DISPLAYED PRODUCT =====\n");

    char buffer[50];
    char code[5];
    char name[50];
    int quantity;

    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    int found = 0;
    printf("%-15s %-20s %-15s\n", "Product Code", "Product Name", "Product Quantity");
    while (fscanf(fp, "%s %s %d", code, name, &quantity) == 3)
    {
        printf("%-15s %-20s %-15d\n", code, name, quantity);
        found = 1;
    }
    if (!found)
    {
        printf("No products found in inventory!\n");
    }

    if (conts)
    {
        printf("\nPRESS ENTER TO CONTINUE....");
        fgets(buffer, sizeof(buffer), stdin);
    }
    printf("\n");

    fclose(fp);
}

void updateProduct(Product prod)
{
    system("cls");
    displayProduct(prod, 0);
    printf("===== UPDATE A PRODUCT =====\n");

    int input;
    do
    {
        int found = 0;
        input = get_integer("Do you want to update the inventory (YES - 1 | NO - 0)\n>>> ");

        if (!(input == 1))
            return;

        FILE *fp = fopen(FILENAME, "r");
        FILE *tempfp = fopen("temp.txt", "w");
        if (fp == NULL || tempfp == NULL)
        {
            printf("Error opening file!\n");
            return;
        }

        char target[10], updateCode;
        printf("Which Product would you like to update (ENTER CODE): ");
        scanf("%s", target);
        getchar();

        int quantity;
        while (fscanf(fp, "%s %s %d", prod.productCode, prod.productName, &prod.productQuantity) == 3)
        {
            if (strcmp(prod.productCode, target) == 0)
            {
                printf("UPDATE CODE: ");
                scanf(" %c", &updateCode);
                while (getchar() != '\n');

                quantity = get_integer("PRODUCT QUANTITY: ");
                if (updateCode == 'A')
                    prod.productQuantity = prod.productQuantity + quantity;
                else if (updateCode == 'S')
                    prod.productQuantity = prod.productQuantity - quantity;

                printf("\n");
                found = 1;
            }
            fprintf(tempfp, "%-15s %-20s %-15d\n", prod.productCode, prod.productName, prod.productQuantity);
        }

        fclose(fp);
        fclose(tempfp);
        remove(FILENAME);
        rename("temp.txt", FILENAME);

        if (found)
            printf("PRODUCT \'%s\' MODIFIED\n\n", target);
        else
            printf("PRODUCT NOT FOUND!\n\n");

    } while (!(input == 0));
}

void deleteProduct(Product prod)
{
    system("cls");
    displayProduct(prod, 0);
    printf("===== DELETE A PRODUCT =====\n");

    int input;
    do
    {
        int found = 0;
        printf("Do you want to delete a product (YES - 1 | NO - 0)\n>>> ");
        scanf("%d", &input);
        if (!(input == 1))
            return;

        FILE *fp = fopen(FILENAME, "r");
        FILE *tempfp = fopen("temp.txt", "w");
        if (fp == NULL || tempfp == NULL)
        {
            printf("Error opening file!\n");
            return;
        }

        char target[10];
        printf("Which product would you like to delete (ENTER PRODUCT CODE): ");
        scanf("%s", target);
        getchar();

        while (fscanf(fp, "%s %s %d", prod.productCode, prod.productName, &prod.productQuantity) == 3)
        {
            if (strcmp(prod.productCode, target) == 0)
            {
                printf("\n");
                found = 1;
                continue;
            }
            fprintf(tempfp, "%-15s %-20s %-15d\n", prod.productCode, prod.productName, prod.productQuantity);
        }

        fclose(fp);
        fclose(tempfp);
        remove(FILENAME);
        rename("temp.txt", FILENAME);

        if (found)
            printf("PRODUCT \'%s\' DELETED\n\n", target);
        else
            printf("PRODUCT NOT FOUND!\n\n");

    } while (!(input == 0));
}

int get_integer(const char *prompt)
{
    int num;
    char term;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%d%c", &num, &term) != 2 || term != '\n')
        {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n');
        }
        else
        {
            return num;
        }
    }
}
