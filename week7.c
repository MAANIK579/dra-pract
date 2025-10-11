#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push();
void pop();
void checkPalindrome();
void demonstrate();
void display();

int main() {
    int choice;

    do {
        printf("\n\n=============== STACK OPERATIONS MENU ===============\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Check if a Number is a Palindrome\n");
        printf("4. Demonstrate Overflow and Underflow\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("===================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                demonstrate();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting the program. Goodbye! 👋\n");
                exit(0);
            default:
                printf("❌ Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

void push() {
    int item;
    if (top == MAX - 1) {
        printf("\n🛑 !! Stack Overflow !! Cannot push more elements.\n");
    } else {
        printf("Enter the element to push: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("✅ %d has been pushed onto the stack.\n", item);
    }
}

void pop() {
    if (top == -1) {
        printf("\n🛑 !! Stack Underflow !! The stack is empty.\n");
    } else {
        int item = stack[top];
        top--;
        printf("✅ Popped element is: %d\n", item);
    }
}

void checkPalindrome() {
    int num, originalNum, remainder;
    long long reversedNum = 0;
    int tempStack[20];
    int tempTop = -1;

    printf("\nEnter an integer to check for palindrome: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Palindrome check is for non-negative numbers.\n");
        return;
    }

    originalNum = num;

    while (num > 0) {
        remainder = num % 10;
        tempTop++;
        tempStack[tempTop] = remainder;
        num = num / 10;
    }

    while (tempTop != -1) {
        int digit = tempStack[tempTop];
        tempTop--;
        reversedNum = reversedNum * 10 + digit;
    }

    if (originalNum == reversedNum) {
        printf("✔️ %d is a palindrome.\n", originalNum);
    } else {
        printf("❌ %d is not a palindrome.\n", originalNum);
    }
}

void demonstrate() {
    int i;
    int originalTop = top;
    int originalStack[MAX];
    for(i = 0; i <= originalTop; i++) {
        originalStack[i] = stack[i];
    }

    printf("\n--- 📈 Demonstrating Overflow ---\n");
    printf("Current stack state saved. Now filling the stack to its MAX size (%d).\n", MAX);

    for (i = top + 1; i < MAX; ++i) {
        top++;
        stack[top] = (i + 1) * 10;
        printf("Pushed %d\n", stack[top]);
    }
    display();

    printf("\nStack is now full. Attempting to push one more element triggers overflow...\n");
    if (top == MAX - 1) {
         printf("🛑 !! Stack Overflow !! Cannot push more elements.\n");
    }

    printf("\n--- 📉 Demonstrating Underflow ---\n");
    printf("Now, emptying the stack by popping all elements.\n");

    while (top != -1) {
        printf("Popped %d\n", stack[top]);
        top--;
    }
    display();

    printf("\nStack is now empty. Attempting to pop one more element triggers underflow...\n");
     if (top == -1) {
        printf("🛑 !! Stack Underflow !! The stack is empty.\n");
    }

    printf("\n--- Demonstration complete. Restoring original stack state. ---\n");
    top = originalTop;
    for(i = 0; i <= top; i++) {
        stack[i] = originalStack[i];
    }
    display();
}

void display() {
    int i;
    if (top == -1) {
        printf("\nStack is empty. 🤷\n");
    } else {
        printf("\nCurrent Stack Status (Top to Bottom):\n");
        printf("Top -> ");
        for (i = top; i >= 0; i--) {
            printf("%d\n       ", stack[i]);
        }
        printf("Bottom\n");
    }
}