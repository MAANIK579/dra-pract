#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertRecursive(struct Node* current, int value) {
    if (current == NULL) {
        return createNode(value);
    }
    if (value < current->data) {
        current->left = insertRecursive(current->left, value);
    } else if (value > current->data) {
        current->right = insertRecursive(current->right, value);
    }
    return current;
}

struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteRecursive(struct Node* current, int value) {
    if (current == NULL) {
        printf("Value not found in the tree.\n");
        return current;
    }

    if (value < current->data) {
        current->left = deleteRecursive(current->left, value);
    } else if (value > current->data) {
        current->right = deleteRecursive(current->right, value);
    } else {
        if (current->left == NULL && current->right == NULL) {
            free(current);
            return NULL;
        } else if (current->left == NULL) {
            struct Node* temp = current->right;
            free(current);
            return temp;
        } else if (current->right == NULL) {
            struct Node* temp = current->left;
            free(current);
            return temp;
        }
        struct Node* successor = findMin(current->right);
        current->data = successor->data;
        current->right = deleteRecursive(current->right, successor->data);
    }
    return current;
}

void inorderRecursive(struct Node* current) {
    if (current == NULL) {
        return;
    }
    inorderRecursive(current->left);
    printf("%d ", current->data);
    inorderRecursive(current->right);
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- BST Operations Menu ---\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Display (In-order Traversal)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insertRecursive(root, value);
                printf("Node %d inserted successfully.\n", value);
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty. Cannot delete.\n");
                } else {
                    printf("Enter the value to delete: ");
                    scanf("%d", &value);
                    root = deleteRecursive(root, value);
                    printf("Attempted to delete node %d.\n", value);
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("In-order Traversal: ");
                    inorderRecursive(root);
                    printf("\n");
                }
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
