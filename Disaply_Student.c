#include "Display_Student.h"

void Displ_Student(){

    FILE *file = fopen(FILE_NAME, "rb");
    if (!file){
        perror("File opening error");
        return;
    }
    
    Student s;
    printf("\n%-20s %-12s %-11s %-5s\n", "FULL NAME", "FACULTU", "GROUP", "GPA");
    printf("--------------------------------------------------\n");
    while (fread(&s, sizeof(Student), 1, file)) {
        printf("%-20s %-12s %-11s %-5.2f\n", s.name, s.faculty, s.group, s.GPA);
    }
    fclose(file);
}