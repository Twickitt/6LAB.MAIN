#include "Find_Student.h"

void Find_Student(){

    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("File opening error");
        return;
    }
    char search[50];
    printf("Enter the searching field (name/faculty/group) with enter: ");
    scanf("%49s", search);
    Student s;
    int found = 0;
    char gpa_str[10];
    while (fread(&s, sizeof(Student), 1, file)) {
        snprintf(gpa_str, sizeof(gpa_str), "%.2f", s.GPA);
        if (strstr(s.name, search) || strstr(s.faculty, search) || strstr(s.group, search) || strstr(gpa_str, search)) {
            printf("\nResults of searching: %s | %s | %s | %.2f\n", s.name, s.faculty, s.group, s.GPA);
            found = 1;
        }
    }
    if (found == 0) {
        printf("No results found\n");
    }
    fclose(file);
}