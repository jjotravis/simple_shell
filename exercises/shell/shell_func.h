#ifndef FUNC_H
#define FUNC_H

#include "shell.h"

/**
 * proc_exec- A function that hanldes process execution
 * @cmd: Command passed (e.g., bin/ls)
 * @argv: Argument Vector Array
 *
 * Return: Nothing
 */

int proc_exec(char *cmd, char *argv[])
{
	pid_t child_proc;
	int status;

	/* Check to see if we have exit */
	if (strcmp(cmd, "exit") == 0)
	{
		exit(1);
	}
	child_proc = fork();
	/* If Child process is created successfully, proceed to execute */
	if (child_proc == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
		{
			printf("Command Not Found\n");
			exit(EXIT_FAILURE);
		}
		sleep(1);
	}
	/* Handle error */
	else if (child_proc == -1)
	{
		perror("Error\n");
		exit(1);
	}
	/* Return to parent process */
	else
	{
		if (wait(&status) == -1)
		{
			perror("Error waiting for child id\n");
			return (-1);
		}
		else
			return (0);
	}
	return (0);
}


/**
 * print_shell- Function that prints a shell to stdout
 * @buffer: String in buffer
 * @size: Size to print to buffer using getline
 *
 * Return: Nothing
 */

void print_shell(char *buffer, size_t size)
{
	int read = 0;
	char pathname[BUFFSIZE], cmd[BUFFSIZE];
	char *argv[3];

	argv[0] = cmd;
	argv[1] = NULL;
	argv[2] = NULL;

	buffer = (char *)malloc(sizeof(char) * BUFFSIZE);

	for (;;)
	{
		/* Reset Pathname */
		strcpy(pathname, "");
		strcpy(cmd, "");

		printf("$: ");

		/* Read will return no. of bytes read. -1 if EOF */
		read = getline(&buffer, &size, stdin);

		/* Handle EOF or Ctrl + D */
		if (read == -1)
			exit(1);

		/* Remove newline read by getline ()*/
		buffer[read - 1] = '\0';

		/* Concatenate to get full command e.g., /bin/ls */
		strcpy(cmd, strcat(pathname, buffer));

		/* Execute process */
		if (proc_exec(cmd, argv) == 0)
			exit(1);
		else
			exit(1);
	}
}
#endif /* FUNC_H */
