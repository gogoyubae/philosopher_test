#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex_lock;
int g_count = 0;

void *t_function(void *data)
{
	int i;
	char *name = (char *)data;
	//critical section
	g_count = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%s COUNT %d\n", name, g_count);
		g_count++;
		sleep(1);
	}
}

int main()
{
	pthread_t p_thread1;
	pthread_t p_thread2;
	int status;

	pthread_create(&p_thread1, NULL, t_function, (void *)"Thread 1");
	pthread_create(&p_thread2, NULL, t_function, (void *)"Thread 2");

	pthread_join(p_thread1, (void *)&status);
	pthread_join(p_thread2, (void *)&status);

	return(0);
}
