#include <stdio.h>
void copy(char a[])
{
	int i = 0;
	int b[100];
	while (a[i] != '\0')
	{
		b[i] = a[i];
		i++;
	}
	b[i] = '\0';
	printf("\n==> Copied String: ");
	for (int j = 0; j < i; j++)
	{
		printf("%c", b[j]);
	}
	printf("\n");
}

int length(char a[])
{
	int len = 0;
	while (a[len] != '\0')
	{
		len++;
	}
	return len;
}

void reverse(char a[], int len)
{
	printf("==> Reversed String: ");
	for (int i = len; i >= 0; i--)
	{
		printf("%c", a[i]);
	}
	printf("\n");
}

void compare(char a[], char b[])
{
	char buffer = 'a';
	scanf("%c", &buffer);
	printf("Enter String B: ");
	scanf("%[^\n]", b);
	int flag = 0;
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0')
	{
		if (a[i] != b[i])
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 0)
	{
		printf("\n==> Both Sentences are Same...\n");
	}
	else
	{
		printf("\n==> Both Sentences are NOT Same...\n");
	}
}

void concat(char a[], char b[])
{
	char buffer = 'a';
	scanf("%c", &buffer);
	printf("Enter String B: ");
	scanf("%[^\n]", b);
	char c[100];
	int i = 0, j = 0;
	int lena = length(a);
	int lenb = length(b);
	while (i < lena)
	{
		c[i] = a[i];
		i++;
		j++;
	}
	i = 0;
	while (i < lenb)
	{
		c[j] = b[i];
		i++;
		j++;
	}
	printf("\n==> Concat String: ");
	for (int k = 0; k < j; k++)
	{
		printf("%c", c[k]);
	}
	printf("\n");
}

void lowertoupper(char a[])
{
	int len = length(a);
	for (int i = 0; i < len; i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z')
		{
			a[i] = a[i] - 32;
		}
	}
	printf("\n==> 'Lower to Upper' String: ");
	for (int j = 0; j < len; j++)
	{
		printf("%c", a[j]);
	}
	printf("\n");
}

int main()
{
	char a[100];
	char b[100];
	int menu = 0;
	printf("Enter the Sentence: ");
	scanf("%[^\n]", a);
	printf("Menu: \n");
	printf("1) Copy String\n");
	printf("2) Find String Length\n");
	printf("3) Compare 2 Strings\n");
	printf("4) String Reversal\n");
	printf("5) Concat 2 Strings\n");
	printf("6) Lower Case to Upper\n");
	printf("==> Enter your Choice: ");
	scanf("%d", &menu);
	int len = length(a);
	switch (menu)
	{
	case 1:
		copy(a);
		break;
	case 2:
		printf("\n==> Length of the String: %d\n", len);
		break;
	case 3:
		compare(a, b);
		break;
	case 4:
		reverse(a, len);
		break;
	case 5:
		concat(a, b);
		break;
	case 6:
		lowertoupper(a);
		break;
	default:
		printf("Invalid Input\n");
		break;
	}
}
