#include <stdio.h>
#include <stdlib.h>

/**
 * main - print "$: " and waits for user input
 * and prints to new line
 *
 * Return: Number of characters read
 */
int main(void)
{
	/*int read;*/
	char *buffer;
	size_t size = 40;

	printf("$: ");
	buffer = malloc(sizeof(char) * size);

	getline(&buffer, &size, stdin);

	printf("%s", buffer);
	return (0);
}

