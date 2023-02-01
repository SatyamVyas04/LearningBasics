#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], array[10][30];
    char replaced[30], new_word[30];
    int i = 0, j = 0, k = 0;

    printf("Enter the string: \n");
    gets(str);
    printf("Word to Find: \n");
    scanf("%s", replaced);
    printf("Word to Replace: \n");
    scanf("%s", new_word);

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

    // Replace Word
    for (i = 0; i <= k; i++)
    {
        if (strcmp(array[i], replaced) == 0)
        {
            strcpy(array[i], new_word);
        }
    }

    printf("String after replacing the word: \n");
    for (i = 0; i <= k; i++)
    {
        printf("%s ", array[i]);
    }
    return 0;
}
