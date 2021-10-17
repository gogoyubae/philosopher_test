#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_info
{
	int heads;
	int die_t;
	int eat_t;
	int sleep_t;
}				t_info;

int main(int argc, char *argv[])
{
	t_info info;

	info->heads = argv[1];
//	info->die_t = argv[2];
//	info->eat_t = argv[3];
//	info->sleep_t = argv[4];

	eat(&info);
}

void eat(t_info *info)
{

}

