#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int a = 15;
	int b = 8;
	int sum;
	pid_t ppid;

	sum = a - b;
	ppid = getppid();
	
	printf("sum is %d\n", sum);
	printf("ppid is %d\n", ppid);

	return (0);
}
