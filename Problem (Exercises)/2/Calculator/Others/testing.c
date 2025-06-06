#include <stdio.h>
#include <stdlib.h>


struct Node {
    int dataNum;
    struct Node* nodeLink;
};

void countLinkedNodes(struct Node* headNode) {
    int count = 0;
    if (headNode == NULL) {
        printf("Linked List Do Not Exist.");
        return;
    }
    struct Node* ptr = NULL;
    ptr = headNode; 
    while(ptr != NULL) {
        count++;
        ptr = ptr->nodeLink;
    }
    printf("Total Node Count: %d", count);
}

void printLinkedNodes(struct Node* headNode) {
    if (headNode == NULL) {
        printf("Linked List Do Not Exist.");
        return;
    }

    struct Node* ptr = NULL;
    ptr = headNode; 

    printf("\nLINKED LIST: \n");
    while(ptr != NULL) {
        printf("%d", ptr->dataNum);
        if (ptr->nodeLink != NULL)
            printf(" -> ");
        else
            printf(" -> NULL"); 
        ptr = ptr->nodeLink;
    }

    printf("\n");
}

void insertNodeAtEnd(struct Node* headNode) {
    if (headNode == NULL) {
        printf("Linked List Do Not Exist.");
    }

    struct Node *temp = malloc(sizeof(struct Node)), *ptr;
    ptr = headNode; 
    
    int addNum;
    printf("\nEnter some Value for the End Node: ");
    scanf("%d", &addNum);

    temp->dataNum = addNum;
    temp->nodeLink = NULL;

    while(ptr->nodeLink != NULL) {
        ptr = ptr->nodeLink;
    }
    ptr->nodeLink = temp;
}

int main(){
    struct Node *head = malloc(sizeof(struct Node));
    head->dataNum = 50;
    head->nodeLink = NULL;

    struct Node *current = malloc(sizeof(struct Node));
    current->dataNum = 60;
    current->nodeLink = NULL;
    head->nodeLink = current;

    current = malloc(sizeof(struct Node));
    current->dataNum = 70;
    current->nodeLink = NULL;

    head->nodeLink->nodeLink = current;

    current = malloc(sizeof(struct Node));
    current->dataNum = 80;
    current->nodeLink = NULL;
    
    head->nodeLink->nodeLink->nodeLink = current;

    countLinkedNodes(head);
    printLinkedNodes(head);
    
    insertNodeAtEnd(head);
    countLinkedNodes(head);
    printLinkedNodes(head);
}
