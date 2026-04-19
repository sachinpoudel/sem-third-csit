#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}


// ========== INSERTION ==========

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);

    if (head != NULL) {
        head->prev = newNode;
    }

    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(int data, int pos) {
    struct Node* newNode = createNode(data);

    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}



void deleteFromBeginning() {
    if (head == NULL) return;

    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) return;

    struct Node* temp = head;

    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

void deleteFromPosition(int pos) {
    if (head == NULL) return;

    struct Node* temp = head;

    if (pos == 1) {
        deleteFromBeginning();
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}


void traverseForward() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void traverseBackward() {
    struct Node* temp = head;

    if (temp == NULL) return;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}


int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtPosition(15, 2);

    traverseForward();
    traverseBackward();

    deleteFromBeginning();
    deleteFromEnd();
    deleteFromPosition(2);

    traverseForward();

    return 0;
}