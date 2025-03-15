#include "Delete_Student.h"
#include "structure.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Del_Student() {
    FILE *file = fopen(NAME, "rb");
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
    printf("Enter the record number to delete (start from number 1): ");
    scanf("%d", &index);
    Student s;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (count == index) {
            deleted = 1;
        } else {
            fwrite(&s, sizeof(Student), 1, temp);
        }
        count++;
    }
    fclose(file);
    fclose(temp);
    if (deleted) {
        remove(NAME);
        rename("temp.dat", NAME);
        printf("Record deleted\n");
    } else {
        remove("temp.dat");
        printf("Error, record not found, choose slot that exists\n");
    }
}
