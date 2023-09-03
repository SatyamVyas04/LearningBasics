#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100], word[100], array[10][30];
    int i = 0, j = 0, k = 0, l = 0;
    printf("Enter the string: \n");
    gets(str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            array[k][j] = '\0';
            k++;
            j = 0;
        }
        else
        {
            array[k][j] = str[i];
            j++;
        }
    }

    array[k][j] = '\0';

    j = 0;
    for (i = 0; i < k; i++)
    {
        int present = 0;
        for (l = 1; l < k + 1; l++)
        {
            if (array[l][j] == '\0' || l == i)
            {
                continue;
            }

            if (strcmp(array[i], array[l]) == 0)
            {
                array[l][j] = '\0';
                present = present + 1;
            }
        }
    }

    j = 0;
    for (i = 0; i < k + 1; i++)
    {
        if (array[i][j] == '\0')
            continue;
        else
            printf("%s ", array[i]);
    }

    printf("\n");

    return 0;
}