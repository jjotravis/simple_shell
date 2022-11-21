#include <stdio.h>

/**
 * main - prints arguements
 * @av: null terminated string
 * @ac: number of commands
 * Return: Always 0 for success
 */
int main(int ac, char **av)
{
	int i;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
