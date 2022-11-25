#include <stdio.h>
#include <stdlib.h>

char read_line(void)
{
	char *line = malloc(1024);
	size_t buffsize = 1024;

	if (getline(&line, &buffsize, stdin))
		printf("%s", line);
	if (feof(stdin))
	{
		printf("\n");
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (*line);
}
