#include <stdio.h>
struct Player
{
    char Name[50];
    int age;
    char add[100];
    int active;
    int married;
    char wife[50];
    int children;
    char c1[50];
    char c2[50];
    char c3[50];
};
void getdata(struct Player p[], int n)
{
    for (int i = 0; i < n; i++)
    {
    	getchar();
        printf("Enter the Name of Player %d: ", i + 1);
        fgets(p[i].Name, 50, stdin);
        getchar();
        printf("Enter the address of Player %d: ", i + 1);
        fgets(p[i].add, 100, stdin);
        printf("Enter the age of Player %d: ", i + 1);
        scanf("%d", &p[i].age);
        printf("Enter 1 if the Player %d is active or enter 0: ", i + 1);
        scanf("%d", &p[i].active);
        printf("Enter 1 if the Player %d is married or enter 0 : ", i + 1);
        scanf("%d", &p[i].married);
        
        if (p[i].married == 1)
        {	
            getchar();
            printf("Enter the Name of wife of Player %d: ", i + 1);
            fgets(p[i].wife, 50, stdin);
            printf("Enter the number of children %d has: ", i + 1);
            scanf("%d", &p[i].children);
            getchar();
            if (p[i].children == 1)
            {
                printf("Name of child 1 of Player %d: ", i + 1);
                fgets(p[i].c1, 50, stdin);
            }
            if (p[i].children == 2)
            {
                printf("Name of child 1 of Player %d: ", i + 1);
                fgets(p[i].c1, 50, stdin);
                printf("Name of child 2 of Player %d:", i + 1);
                fgets(p[i].c2, 50, stdin);
            }
            if (p[i].children == 3)
            {
                printf("Name of child 1 of Player %d: ", i + 1);
                fgets(p[i].c1, 50, stdin);
                printf(" Name of child 2 of Player %d: ", i + 1);
                fgets(p[i].c2, 50, stdin);
                printf(" Name of child 3 of Player %d: ", i + 1);
                fgets(p[i].c3, 50, stdin);

            }
        }
    }
}
void printdata(struct Player p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i].active)
        {
            printf("\nName: %s", p[i].Name);
            printf("Age: %d\n", p[i].age);
            printf("Address: %s", p[i].add);
            if (p[i].married)
            {
                printf("Name of wife: %s", p[i].wife);
                if (p[i].children == 1)
                {
                    printf(" child 1 : %s", p[i].c1);
                }
                if (p[i].children == 2)
                {
                    printf(" child 1 : %s", p[i].c1);
                    printf(" child 2 : %s", p[i].c2);
                }
                if (p[i].children == 3)
                {
                    printf(" child 1 : %s", p[i].c1);
                    printf(" child 2 : %s", p[i].c2);
                    printf(" child 3 : %s", p[i].c3);
                }
            }
        }
    }
}
int main()
{
    int n;
    printf("No. of Players: ");
    scanf("%d", &n);
    struct Player p[n];
    getdata(p, n);
    printdata(p, n);
    return 0;
}
