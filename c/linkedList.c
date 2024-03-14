#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* nextNode; 
};

struct LinkedList {
    struct Node* head;
};

struct Node* createNode(int);
void insertBeginning(struct LinkedList*, int);
void display(struct LinkedList*);
void cleanup(struct LinkedList*);
void deleteNode(struct LinkedList* linkedList, int value);

int main(void) {
    struct LinkedList ll = {.head = NULL}; // don't forget to initialize!

    insertBeginning(&ll, 42);
    insertBeginning(&ll, 52);
    insertBeginning(&ll, 62);

    display(&ll);

    deleteNode(&ll, 52); 
    deleteNode(&ll, 53); // item not found in list

    display(&ll);

    cleanup(&ll);

    return 0;
}

void cleanup(struct LinkedList* linkedList) {
    struct Node* current = linkedList->head;
    while (current != NULL) {
        struct Node* temp = current->nextNode;  // this is necessary...
        free(current);                          // otherwise you lose access to nextNode here
        current = temp;
        free(temp);
    }
    printf("Cleanup successful!\n");
}

void deleteNode(struct LinkedList* linkedList, int value) {
    struct Node* current = linkedList->head;
    while (current->nextNode != NULL) {
        if (current->nextNode->data == value) {
            struct Node* temp = current->nextNode->nextNode;
            free(current->nextNode->nextNode);
            current->nextNode->nextNode = NULL;
            current->nextNode = current->nextNode->nextNode;
            printf("Value removed successfully!\n\n");
            return;
        }
        current = current->nextNode;
    }
    printf("Item not found in list.\n\n");
}

void display(struct LinkedList* linkedList) {
    struct Node* current = linkedList->head;
    while (current != NULL) {
        printf("Node value: %d\n", current->data);
        current = current->nextNode;
    }
    printf("\n");
}

struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed...\n");
        free(newNode);
        exit(1);
    }
    newNode->data = value;
    newNode->nextNode = NULL;
    return newNode;
}

void insertBeginning(struct LinkedList* linkedList, int value) {
    struct Node* newNode = createNode(value);
    newNode->nextNode = linkedList->head;
    linkedList->head = newNode;
}