#include "structure.h"
#include "Add_Student.h"
#include "Delete_Student.h"
#include "Find_Student.h"
#include "Edit_Student.h"
#include "Display_Student.h"

#define  N 1

#define NAME "stud.dat"

void (*menu[])(void) = {Add_Student, Del_Student, Find_Student, Edit_Student, Displ_Student};


int main(){

    #if N == 1
    FILE *file = fopen(NAME, "w");
    fseek(file, 0, SEEK_SET);
    Student predefStud[] = {
        {"Alice Johnson", "Engineering", "E21", 3.8},
        {"Bob Smith", "Math", "M2", 3.5},
        {"Chan Sun", "Math", "M2", 5},
        {"Charlie Brown", "Physics", "245", 3.9}
    };
    fwrite(predefStud, sizeof(Student), 4, file);
    fclose(file);
    #endif


    int choice;

    do{
        printf("\nMenu\n");
        printf("1. Add student\n");
        printf("2. Delete student\n");
        printf("3. Find student\n");
        printf("4. Edit student data\n");
        printf("5. Display students\n");
        printf("0. Exit\n");
        printf("Select action: ");
        scanf("%d", &choice);
        if (1<= choice && choice <= 5){
            menu[choice - 1]();
        }
           
        if (choice < 0 || choice > 5){
            printf("Command with such number doesn't exist, try again\n");
        }
    } while (choice != 0);
    return 0;
}
