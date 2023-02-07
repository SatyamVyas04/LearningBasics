#include <stdio.h>
#include <string.h>
struct airline
{
    char s[4];
    int start_time;
    char d[4];
    int arr_time;
    int seats;
};
struct airline getinfo(struct airline a)
{
    char temp1[4];
    char temp2[4];
    printf("Starting point:");
    scanf("%s", temp1);
    strcpy(a.s, temp1);
    printf("Starting Time:");
    scanf("%d", &a.start_time);
    printf("Destination:");
    scanf("%s", temp2);
    strcpy(a.d, temp2);
    printf("Arrival Time:");
    scanf("%d", &a.arr_time);
    printf("Number of seats:");
    scanf("%d", &a.seats);
    return a;
}
void bookticket(int x, struct airline a[x])
{
    int n = 1;
    while (n)
    {
        char temp1[4];
        char temp2[4];
        int temp3;
        char temp[4];
        getchar();
        printf("==> Starting point:");
        scanf("%s", temp1);
        strcpy(temp, temp1);
        printf("==> Destination:");
        scanf("%s", temp2);
        printf("==> Number of seats:");
        scanf("%d", &temp3);
        int check = 0;
        for (int i = 0; i < x; i++)
        {
            if ((strncmp(temp, a[i].s, 3) == 0) && (strncmp(temp2, a[i].d, 3) == 0) &&
                (temp3 <= a[i].seats))
            {
                printf("\n# Flight is available\n");
                a[i].seats -= temp3;
                printf("=> Flight details:\n");
                printf("-> Start point: %s\n", a[i].s);
                printf("-> Destination: %s\n", a[i].d);
                printf("-> Time: %d to %d\n", a[i].start_time, a[i].arr_time);
                printf("-> Tickets booked: %d\n\n", temp3);
                check++;
                break;
            }
        }
        if (check == 0)
            printf("==> Unable to book the flight\n");
        printf("==> To continue booking press 1\nTo exit press 0\n");
        scanf("%d", &n);
    }
}
int main()
{
    int n;
    printf("Enter the number of flights\n");
    scanf("%d", &n);
    struct airline a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = getinfo(a[i]);
        printf("\n");
    }
    bookticket(n, a);
    return 0;
}