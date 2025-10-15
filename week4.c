#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

void insertAtBeginning(int data);
void insertAtEnd(int data);
void deleteFromBeginning();
void deleteFromEnd();
void deleteElement(int key);
void display();

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    if (last == NULL) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    printf("%d inserted at the beginning.\n", data);
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    if (last == NULL) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("%d inserted at the end.\n", data);
}

void display() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = last->next;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(Head: %d)\n", last->next->data);
}

void deleteFromBeginning() {
    if (last == NULL) {
        printf("Underflow: List is empty.\n");
        return;
    }

    struct Node* temp = last->next;
    int deletedData = temp->data;

    if (last->next == last) {
        last = NULL;
    } else {
        last->next = temp->next;
    }

    free(temp);
    printf("%d deleted from the beginning.\n", deletedData);
}

void deleteFromEnd() {
    if (last == NULL) {
        printf("Underflow: List is empty.\n");
        return;
    }

    struct Node* temp = last;
    int deletedData = temp->data;

    if (last->next == last) {
        last = NULL;
    } else {
        struct Node* current = last->next;
        while (current->next != last) {
            current = current->next;
        }
        current->next = last->next;
        last = current;
    }

    free(temp);
    printf("%d deleted from the end.\n", deletedData);
}

void deleteElement(int key) {
    if (last == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* current = last->next;
    struct Node* prev = last;

    do {
        if (current->data == key) {
            if (current == last->next) {
                deleteFromBeginning();
            }
            else if (current == last) {
                deleteFromEnd();
            }
            else {
                prev->next = current->next;
                free(current);
                printf("%d has been deleted.\n", key);
            }
            return;
        }
        prev = current;
        current = current->next;
    } while (current != last->next);

    printf("Element %d not found in the list.\n", key);
}

int main() {
    int choice, value;

    do {
        printf("\n--- Singly Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Delete a specific element\n");
        printf("6. Display List\n");
        printf("0. Exit\n");
        printf("--------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 3:
            deleteFromBeginning();
            break;
        case 4:
            deleteFromEnd();
            break;
        case 5:
            printf("Enter element to delete: ");
            scanf("%d", &value);
            deleteElement(value);
            break;
        case 6:
            display();
            break;
        case 0:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
