#include "Display_Student.h"
#include "structure.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Displ_Student(){

    FILE *file = fopen(NAME, "rb");
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