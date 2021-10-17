#include <stdio.h>
#include <unistd.h>

int main()
{
	while(1)
	{
		printf("1second\n");
		usleep(1000*1000);
	}
}

