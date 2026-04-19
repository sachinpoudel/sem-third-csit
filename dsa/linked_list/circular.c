#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void insertAtPosition(int data, int pos) {
    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = head;

    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteFromBeginning() {
    if (head == NULL) return;

    struct Node *temp = head, *last = head;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) return;

    struct Node *temp = head, *prev = NULL;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

// ========== TRAVERSAL ==========

void traverse() {
    if (head == NULL) return;

    struct Node* temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}


int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtPosition(15, 2);

    traverse();

    deleteFromBeginning();
    deleteFromEnd();

    traverse();

    return 0;
}