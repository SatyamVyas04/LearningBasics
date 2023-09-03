#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 10
#define NAME_LENGTH 20
#define RETIREMENT_AGE 60

typedef struct
{
    int year;
    int month;
    int day;
} Date;

typedef struct
{
    char name[NAME_LENGTH];
    char gender;
    int salary;
    Date dob;
} Record;

typedef union
{
    char name[NAME_LENGTH];
    char gender;
} AmendmentData;

typedef struct
{
    char type; // 'N' for new employee, 'U' for update, 'L' for leaving
    AmendmentData data;
    int salary;
    Date dob;
} Amendment;

bool isRetired(Date dob)
{
    int age = 2023 - dob.year;
    if (age >= RETIREMENT_AGE)
    {
        return true;
    }
    return false;
}

int main()
{
    Record employees[MAX_EMPLOYEES];
    int numEmployees = 0;

    // Input 10 records
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        printf("Enter record for employee %d\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        getchar();
        printf("Gender: ");
        scanf("%c", &employees[i].gender);
        printf("Salary: ");
        scanf("%d", &employees[i].salary);
        printf("Date of birth (YYYY MM DD): ");
        scanf("%d %d %d", &employees[i].dob.year, &employees[i].dob.month, &employees[i].dob.day);
        numEmployees++;
    }

    // Input 5 amendments
    for (int i = 0; i < 5; i++)
    {
        Amendment amendment;
        printf("Enter amendment %d\n", i + 1);
        printf("Type (N for new, U for update, L for leaving): ");
        scanf(" %c", &amendment.type);
        switch (amendment.type)
        {
        case 'N':
            printf("Name: ");
            scanf("%s", amendment.data.name);
            getchar();
            printf("Gender: ");
            scanf("%c", &amendment.data.gender);
            printf("Salary: ");
            scanf("%d", &amendment.salary);
            printf("Date of birth (YYYY MM DD): ");
            scanf("%d %d %d", &amendment.dob.year, &amendment.dob.month, &amendment.dob.day);
            employees[numEmployees++] = (Record){
                .name = amendment.data.name,
                .gender = amendment.data.gender,
                .salary = amendment.salary,
                .dob = amendment.dob};
            break;
        case 'U':
            printf("Name: ");
            scanf("%s", amendment.data.name);
            printf("Salary: ");
            scanf("%d", &amendment.salary);
            for (int j = 0; j < numEmployees; j++)
            {
                if (strcmp(employees[j].name, amendment.data.name) == 0)
                {
                    employees[j].salary = amendment.salary;
                    break;
                }
            }
            break;
        case 'L':
            printf("Name: ");
            scanf("%s", amendment.data.name);
            for (int j = 0; j < numEmployees; j++)
            {
                if (strcmp(employees[j].name, amendment.data.name) == 0)
                {
                    employees[j].salary = 0;
                    break;
                }
            }
            break;
        }
    }

    // Remove retired employees
    int j = 0;
    for (int i = 0; i < numEmployees; i++)
    {
        if (!isRetired(employees[i].dob))
        {
            employees[j++] = employees[i];
        }
    }
    numEmployees = j;

    // Print updated records
    printf("\nUpdated records:\n");
    for (int i = 0; i < numEmployees; i++)
    {
        printf("Employee %d\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("Gender: %c\n", employees[i].gender);
        printf("Salary: %d\n", employees[i].salary);
        printf("Date of birth: %d-%02d-%02d\n", employees[i].dob.year, employees[i].dob.month, employees[i].dob.day);
    }

    return 0;
}
