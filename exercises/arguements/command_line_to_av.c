#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - splits a string and returns an array of each word of the string
 *
 * Return: Always 0 on succes
 */

int main(void)
{
	char *token;
	char s1[] = "How does this work";

	token = strtok(s1, " ");

	while(token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
