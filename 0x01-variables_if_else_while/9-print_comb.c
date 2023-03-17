#include <stdio.h>

/**
 * main - prints all combinations of single-digit numbers
 * Return: Always 0
 */
int main(void)
{

	int n;

	for (n = '0'; n <= '9'; n++)
	{
		putchar(n);
		if (n == '9')
		{
			break;
		}
		else
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}

