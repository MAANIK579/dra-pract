#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Day {
    char *dayName;
    int date;
    char *activityDescription;
};
struct Day* createCalendar();
void readCalendar(struct Day *calendar);
void displayCalendar(struct Day *calendar);
int main() {
    struct Day *myWeek;
    printf("--- Weekly Activity Calendar Program ---\n");
    myWeek = createCalendar();
    if (myWeek != NULL) {
        readCalendar(myWeek);
        displayCalendar(myWeek);
        printf("\nFreeing allocated memory...\n");
        for (int i = 0; i < 7; i++) {
            free(myWeek[i].dayName);
            free(myWeek[i].activityDescription);
        }
        free(myWeek);
        printf("Memory freed successfully. Exiting program.\n");
    }
    return 0;
}
struct Day* createCalendar() {
    printf("\nInitializing calendar...\n");
    struct Day *calendar = (struct Day *) malloc(7 * sizeof(struct Day));
    if (calendar == NULL) {
        printf("Error: Memory allocation failed for the calendar!\n");
        return NULL;
    }
    return calendar;
}
void readCalendar(struct Day *calendar) {
    printf("Please enter the details for each day.\n\n");
    for (int i = 0; i < 7; i++) {
        printf("--- Entering details for Day %d ---\n", i + 1);
        calendar[i].dayName = (char *) malloc(50 * sizeof(char));
        calendar[i].activityDescription = (char *) malloc(100 * sizeof(char));
        if (calendar[i].dayName == NULL || calendar[i].activityDescription == NULL) {
            printf("Error: Memory allocation failed for day details!\n");
            return;
        }
        printf("Enter Day Name (e.g., Monday): ");
        scanf("%49s", calendar[i].dayName);
        printf("Enter Date (e.g., 6): ");
        scanf("%d", &calendar[i].date);
        while (getchar() != '\n'); 
        printf("Enter Activity: ");
        fgets(calendar[i].activityDescription, 100, stdin);
        calendar[i].activityDescription[strcspn(calendar[i].activityDescription, "\n")] = 0;
        printf("\n");
    }
}
void displayCalendar(struct Day *calendar) {
    printf("\n\n==============================================\n");
    printf("        *** Weekly Activity Report ***\n");
    printf("==============================================\n");
    printf("%-15s | %-5s | %-30s\n", "Day", "Date", "Activity");
    printf("----------------------------------------------\n");

    for (int i = 0; i < 7; i++) {
        printf("%-15s | %-5d | %-30s\n", 
               calendar[i].dayName, 
               calendar[i].date, 
               calendar[i].activityDescription);
    }
    printf("==============================================\n");
}
