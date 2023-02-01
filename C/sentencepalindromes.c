#include <stdio.h>
int main()
{
    char str[100], array[10][30];
    int i = 0, j = 0, k = 0, len1 = 0;
    printf("Enter the string: \n");
    scanf("%[^\n]", str);

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

    // Palindrome check
    for (i = 0; i <= k; i++)
    {
        len1 = strlen(array[i]);
        int j = 0;
        while (j < len1 / 2)
        {
            if (tolower(array[i][j]) != tolower(array[i][len1 - j - 1]))
            {
                break;
            }
            j++;
        }
        if (j == len1 / 2)
            printf("%s ", array[i]);
    }
    printf("\n");
    return 0;
}