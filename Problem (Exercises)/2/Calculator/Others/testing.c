#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dataNum;
    struct Node* nodeLink;
};

/* Function Prototypes */
void countLinkedNodes(struct Node* headNode);
void printLinkedNodes(struct Node* headNode);
struct Node* insertNodeAtStart(struct Node* headNode);
struct Node* insertNodeAtEnd(struct Node* headNode);
struct Node* insertNodeAtPosition(struct Node* headNode, int position);

int main() {
    /* ✅ Step 1: Initialize Linked List */
    struct Node *head = malloc(sizeof(struct Node));
    if (!head) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    head->dataNum = 50;
    head->nodeLink = NULL;

    struct Node *current;
    int values[] = {60, 70, 80}; // Additional nodes
    for (int i = 0; i < 3; i++) {
        current = malloc(sizeof(struct Node));
        if (!current) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        current->dataNum = values[i];
        current->nodeLink = NULL;

        struct Node *ptr = head;
        while (ptr->nodeLink != NULL) {
            ptr = ptr->nodeLink;
        }
        ptr->nodeLink = current;
    }

    /* ✅ Step 2: Print Initial Linked List */
    countLinkedNodes(head);
    printLinkedNodes(head);

    /* ✅ Step 3: Insert Node at the Start */
    head = insertNodeAtStart(head);
    countLinkedNodes(head);
    printLinkedNodes(head);

    /* ✅ Step 4: Insert Node at the End */
    head = insertNodeAtEnd(head);
    countLinkedNodes(head);
    printLinkedNodes(head);

    /* ✅ Step 5: Insert Node at Specific Position */
    int position;
    printf("\nEnter position for new node insertion: ");
    scanf("%d", &position);
    head = insertNodeAtPosition(head, position);
    countLinkedNodes(head);
    printLinkedNodes(head);

    return 0;
}

/* Counts the number of nodes */
void countLinkedNodes(struct Node* headNode) {
    int count = 0;
    if (headNode == NULL) {
        printf("Linked List Does Not Exist.\n");
        return;
    }
    struct Node* ptr = headNode; 
    while (ptr != NULL) {
        count++;
        ptr = ptr->nodeLink;
    }
    printf("Total Node Count: %d\n", count);
}

/* Prints the linked list */
void printLinkedNodes(struct Node* headNode) {
    if (headNode == NULL) {
        printf("Linked List Does Not Exist.\n");
        return;
    }
    struct Node* ptr = headNode;
    printf("\nLINKED LIST:\n");
    while (ptr != NULL) {
        printf("%d", ptr->dataNum);
        if (ptr->nodeLink != NULL)
            printf(" -> ");
        else
            printf(" -> NULL"); 
        ptr = ptr->nodeLink;
    }
    printf("\n");
}

/* Inserts a node at the start */
struct Node* insertNodeAtStart(struct Node* headNode) {
    struct Node* temp = malloc(sizeof(struct Node));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return headNode;
    }

    int addNum;
    printf("\nEnter value for the Start Node: ");
    scanf("%d", &addNum);

    temp->dataNum = addNum;
    temp->nodeLink = headNode; // Point new node to old head
    return temp; // Return new head
}

/* Inserts a node at any position */
struct Node* insertNodeAtPosition(struct Node* headNode, int position) {
    struct Node* temp = malloc(sizeof(struct Node));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return headNode;
    }

    int addNum;
    printf("\nEnter value for the new node: ");
    scanf("%d", &addNum);
    temp->dataNum = addNum;

    if (position == 1) {  // Special case: Insert at head
        temp->nodeLink = headNode;
        return temp;
    }

    struct Node* ptr = headNode;
    for (int i = 1; i < position - 1 && ptr->nodeLink != NULL; i++) {
        ptr = ptr->nodeLink;
    }

    temp->nodeLink = ptr->nodeLink;
    ptr->nodeLink = temp;
    return headNode;  // Return unchanged head
}

/* Inserts a node at the end */
struct Node* insertNodeAtEnd(struct Node* headNode) {
    if (headNode == NULL) {
        printf("Linked List Does Not Exist.\n");
        return NULL;
    }

    struct Node *temp = malloc(sizeof(struct Node)), *ptr = headNode;
    if (!temp) {
        printf("Memory allocation failed!\n");
        return headNode;
    }

    int addNum;
    printf("\nEnter value for the End Node: ");
    scanf("%d", &addNum);

    temp->dataNum = addNum;
    temp->nodeLink = NULL;

    while (ptr->nodeLink != NULL) {
        ptr = ptr->nodeLink;
    }
    ptr->nodeLink = temp;

    return headNode;  // Return unchanged head
}
