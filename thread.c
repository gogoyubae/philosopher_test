#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;
int g_count = 0;

void *t_function(void *data)
{
	int i;
	char *name = (char *)data;

	pthread_mutex_lock(&mutex);

	//critical section
	g_count = 0;
	for (i = 0; i < 7; i++)
	{
		printf("%s COUNT %d\n", name, g_count);
		g_count++;
		sleep(1);
	}
	//critical section

	pthread_mutex_unlock(&mutex);
}

int main()
{
	pthread_t p_thread1;
	pthread_t p_thread2;

	pthread_mutex_init(&mutex, NULL);

	pthread_create(&p_thread1, NULL, t_function, (void *)"Thread 1");
	pthread_create(&p_thread2, NULL, t_function, (void *)"Thread 2");

	pthread_join(p_thread1, NULL);
	pthread_join(p_thread2, NULL);

	pthread_mutex_destroy(&mutex);

	return(0);
}
