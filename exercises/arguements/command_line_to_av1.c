#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - separates string in command line using strtok
 *
 * Return: Always 0 for success
 */
int main(void)
{
	char *buffer;
	size_t len;
	char *token;

	buffer = malloc(1024);
	len = 1024;

	while(1)
	{
		printf("$ ");
		getline(&buffer, &len, stdin);
		printf("buffer getline: %s", buffer);

		token = strtok(buffer, " ");
		while (token)
		{
			printf("buffer strtok: %s\n", token);
			token = strtok(NULL, " ");
		}
	}
	return (0);
}
