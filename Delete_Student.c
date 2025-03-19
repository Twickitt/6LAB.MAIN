#include "Delete_Student.h"
#include "Structure.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Delete_Student() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("File opening error");
        return;
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    if (fileSize == 0) {
        printf("Error, no students in the list to delete\n");
        fclose(file);
        return;
    }
    rewind(file);
    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        perror("Error while creating temp file");
        fclose(file);
        return;
    }
    int index, count = 1, deleted = 0;
    printf("\nEnter the record number to delete (start from number 1): ");
    scanf("%d", &index);
    Student s;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (count == index) {
            deleted = 1;
            printf("\nStudent's № %d data: %s | %s | %s | %.2f\n", index, s.name, s.faculty, s.group, s.GPA);
        } else {
            fwrite(&s, sizeof(Student), 1, temp);
        }
        count++;
    }
    fclose(file);
    fclose(temp);
    if (deleted) {
        remove(FILE_NAME);
        rename("temp.dat", FILE_NAME);
        printf("Record №%d successfully deleted\n", index);
    } else {
        remove("temp.dat");
        printf("Error, record not found, choose valid slot\n");
    }
}
