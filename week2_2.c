#include <stdio.h>

void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    tower_of_hanoi(n - 1, source, auxiliary, destination);
    
    printf("Move disk %d from %c to %c\n", n, source, destination);
    
    tower_of_hanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n_disks;
    printf("Enter the number of disks for the Tower of Hanoi: ");
    scanf("%d", &n_disks);
    
    if (n_disks < 1) {
        printf("Please enter a positive number of disks.\n");
        return 1;
    }

    printf("\nSolving Tower of Hanoi for %d disks:\n", n_disks);
    tower_of_hanoi(n_disks, 'A', 'C', 'B');
    
    return 0;
}
