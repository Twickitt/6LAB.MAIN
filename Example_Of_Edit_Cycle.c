do {
        printf("\nWhat do you want to edit?\n");
        printf("1. Full Name\n");
        printf("2. Faculty\n");
        printf("3. Group\n");
        printf("4. GPA\n");
        printf("Select option: ");
        scanf("%d", &choice);
        getchar(); // Очистка буфера

        switch (choice) {
            case 1:
                printf("Enter new Full Name: ");
                fgets(s.name, sizeof(s.name), stdin);
                s.name[strcspn(s.name, "\n")] = 0;
                break;
            case 2:
                printf("Enter new Faculty: ");
                fgets(s.faculty, sizeof(s.faculty), stdin);
                s.faculty[strcspn(s.faculty, "\n")] = 0;
                break;
            case 3:
                printf("Enter new Group: ");
                fgets(s.group, sizeof(s.group), stdin);
                s.group[strcspn(s.group, "\n")] = 0;
                break;
            case 4:
                printf("Enter new GPA: ");
                scanf("%f", &s.GPA);
                getchar();
                break;
            default:
                printf("Invalid option, try again\n");
        }
    } while ((choice < 0 || choice > 4) && choice != 0);

    
    fseek(file, (index - 1) * sizeof(Student), SEEK_SET);
    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);
    printf("Record updated\n");
}