#include <stdio.h>
int main()
{
    char str[100], word[100], array[10][30];
    int i = 0, j = 0, k = 0, len1 = 0, len2 = 0, l = 0;
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

    // Replace Word
    char replace[100];
    printf("Enter the word to be replaced: ");
    gets(replace);
    
    return 0;
}