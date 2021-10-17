#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *t_function(void *param)
{
	for (int i = 1; i <= 10; i++)
	{
		usleep(1000*1000*2);
		printf("%s:", (char *)param);
		printf("execute thread function %d\n", i);
	}
	printf("exit function\n");
	return (void *)2147483647;
}

int main()
{
	pthread_t p_thread1;
	pthread_t p_thread2;
	int id1;
	int id2;

	id1 = pthread_create(&p_thread1, NULL, t_function, "thread1");
	id2 = pthread_create(&p_thread2, NULL, t_function, "thread2");

	if (id1 < 0 || id2 < 0)
	{
		perror("thread create error:");
		exit(0);
	}
	//pthread_detach(p_thread1);
	//pthread_detach(p_thread2);
	pthread_join(p_thread1, 0);
	pthread_join(p_thread2, 0);

	int s = 0;
	while(42)
	{
		printf("%dseconds later\n", s++);
		usleep(1000*1000);
	}
	printf("main() finish\n");
	return (0);
}
