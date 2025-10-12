#include <stdio.h>
int string_length(char s[]);
void find_and_replace(char str[], char pat[], char rep[]);
int main() {
    char str[200], pat[100], rep[100];
    printf("Enter the main string (STR): ");
    gets(str);
    printf("Enter the pattern to find (PAT): ");
    gets(pat);
    printf("Enter the string to replace it with (REP): ");
    gets(rep);
    find_and_replace(str, pat, rep);
    return 0;
}
int string_length(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}
void find_and_replace(char str[], char pat[], char rep[]) {
    int str_len, pat_len, rep_len;
    int i = 0, j, k;
    int match_found = 0;
    char result[500];
    int res_index = 0;
    str_len = string_length(str);
    pat_len = string_length(pat);
    rep_len = string_length(rep);
    while (i < str_len) {
        j = 0;
        k = i;
        while (str[k] == pat[j] && j < pat_len) {
            k++;
            j++;
        }
        if (j == pat_len) {
            match_found = 1;
            for (k = 0; k < rep_len; k++) {
                result[res_index++] = rep[k];
            }
            i += pat_len;
        } else {
            result[res_index++] = str[i];
            i++;
        }
    }
    result[res_index] = '\0';
    if (match_found) {
        printf("\n--- Pattern Found and Replaced ---\n");
        printf("The final modified string is: %s\n", result);
    } else {
        printf("\n--- Pattern Not Found ---\n");
        printf("The pattern '%s' does not exist in the main string.\n", pat);
    }
}
