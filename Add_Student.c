#include "Add_Student.h"
#include "Structure.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Add_Student(){

    FILE *file = fopen(NAME, "ab");
    if (!file){
        perror("File opening error");
        return;
    }

    Student s;
    getchar();
    printf("Enter Full name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0;
    printf("Enter faculty: ");
    fgets(s.faculty, sizeof(s.faculty), stdin);
    s.faculty[strcspn(s.faculty, "\n")] = 0;
    printf("Enter group number: ");
    fgets(s.group, sizeof(s.group), stdin);
    s.group[strcspn(s.group, "\n")] = 0;
    printf("Enter GPA: ");
    scanf("%f", &s.GPA);
    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);
    printf("\nStudent added\n");
}
