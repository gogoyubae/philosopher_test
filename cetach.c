#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *t_function(void *param)
{
	for (int i = 1; i <= 5; i++)
	{
		usleep(1000*1000*2);
	}
	printf("exit function\n");
	return (void *)2147483647;
}

int main()
{
	pthread_t p_thread1;
	int id1;
	int res;

	id1 = pthread_create(&p_thread1, NULL, t_function, "thread1");

	if (id1 < 0)
	{
		perror("thread create error:");
		exit(0);
	}
	pthread_join(p_thread1, (void *)&res);
	printf("exit main\n");
	return 0;
}
