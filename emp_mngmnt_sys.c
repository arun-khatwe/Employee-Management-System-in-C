#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    char Name[50];
    int EmpID;
    char Destination[20];
    int Experience;
    int Age; 
} Employee;

void insertEmp(Employee employees[], int *count);
void deleteEmp(Employee employees[], int *count);
void searchEmp(Employee employees[], int count);
void displayEmp(Employee employees[], int count);

int main() {
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    while (1) {
        // Display the menu
        printf("\n --> Employee Management System <--\n");
        printf("1. Insert New Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Search Employee\n");
        printf("4. Display All Employees\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertEmp(employees, &count);
                break;
            case 2:
                deleteEmp(employees, &count);
                break;
            case 3:
                searchEmp(employees, count);
                break;
            case 4:
                displayEmp(employees, count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void insertEmp(Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Cannot add more employees. Maximum limit reached.\n");
        return;
    }

    printf("Enter Employee Name: ");
    scanf("%s", employees[*count].Name);
    printf("Enter Employee ID: ");
    scanf("%d", &employees[*count].EmpID);
    printf("Enter Employee Destination: ");
    scanf("%s", employees[*count].Destination);
    printf("Enter Employee Experience (years): ");
    scanf("%d", &employees[*count].Experience);
    printf("Enter Employee Age: ");
    scanf("%d", &employees[*count].Age);

    (*count)++;
    printf("Employee added successfully!\n");
}

void deleteEmp(Employee employees[], int *count) {
    if (*count == 0) {
        printf("No employees to delete.\n");
        return;
    }

    int id, i, found = 0;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++) {
        if (employees[i].EmpID == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int j = i; j < *count - 1; j++) {
            employees[j] = employees[j + 1];
        }
        (*count)--;
        printf("Employee deleted successfully!\n");
    } else {
        printf("Employee ID not found.\n");
    }
}

void searchEmp(Employee employees[], int count) {
    if (count == 0) {
        printf("No employees to search.\n");
        return;
    }

    int id, found = 0;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].EmpID == id) {
            printf("Employee Found:\n");
            printf("Name: %s\n", employees[i].Name);
            printf("ID: %d\n", employees[i].EmpID);
            printf("Destination: %s\n", employees[i].Destination);
            printf("Experience: %d years\n", employees[i].Experience);
            printf("Age: %d\n", employees[i].Age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee ID not found.\n");
    }
}

void displayEmp(Employee employees[], int count) {
    if (count == 0) {
        printf("No employees to display.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: %s\n", employees[i].Name);
        printf("ID: %d\n", employees[i].EmpID);
        printf("Destination: %s\n", employees[i].Destination);
        printf("Experience: %d years\n", employees[i].Experience);
        printf("Age: %d\n", employees[i].Age);
    }
}


