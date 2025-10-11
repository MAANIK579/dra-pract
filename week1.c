#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, max_idx;
    for (i = 0; i < n - 1; i++) {
        max_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        int temp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int bubble_list[] = {64, 34, 25, 12, 22, 11, 90};
    int n_bubble = sizeof(bubble_list) / sizeof(bubble_list[0]);
    
    printf("Original list for Bubble Sort: ");
    printArray(bubble_list, n_bubble);

    bubbleSort(bubble_list, n_bubble);
    printf("Sorted list (Ascending order) using Bubble Sort: ");
    printArray(bubble_list, n_bubble);

    printf("----------------------------------------\n");

    int selection_list[] = {64, 25, 12, 22, 11};
    int n_selection = sizeof(selection_list) / sizeof(selection_list[0]);

    printf("Original list for Selection Sort: ");
    printArray(selection_list, n_selection);
    
    selectionSort(selection_list, n_selection);
    printf("Sorted list (Descending order) using Selection Sort: ");
    printArray(selection_list, n_selection);

    return 0;
}
