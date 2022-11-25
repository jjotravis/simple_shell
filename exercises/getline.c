#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t n = 10;
	char *buf = NULL;

	printf("Enter name: ");
	getline(&buf, &n, stdin);

	printf("Name is %s buffer size is %ld\n", buf, n);

	free(buf);
}
