/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:14:32 by yubae             #+#    #+#             */
/*   Updated: 2022/01/11 20:48:32 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     launch(t_info *info, int i)
{
	pthread_t tid;
	t_philo *philo;
	
	philo = info->philo;
	while (i < info->heads)
	{
		pthread_create(&tid, 0, p_thread, &philo[i]);
		i += 2;
	}
//	pthread_join(tid, 0);
	pthread_detach(tid);
	return (1);
}

int     init_philo(t_philo *philo, t_info *info)
{
	int num;
	t_philo *tmp;
	
	num = 0;
	tmp = philo;
	while (num < info->heads)
	{
		tmp = &philo[num];
		tmp->num = num + 1;
		tmp->eatcnt = 0;
		tmp->info = info;
	    if (num + 1 == info->heads)
	    {
	        tmp->left = &info->forks[num];
	        tmp->right = &info->forks[0];
	    //    printf("left %d right %d\n",num, 0);
	    }
	    else
	    {
	        tmp->left = &info->forks[num];
	        tmp->right = &info->forks[num + 1];
	      //`  printf("left %d right %d\n",num, num + 1);
	    }
		num++;
	}
    return (1);
}


void init_info(int argc, char *argv[], int *argv_num, t_info *info)
{
	info->heads = argv_num[1];
	info->die_t = argv_num[2];
	info->eat_t = argv_num[3];
	info->sleep_t = argv_num[4];
	if (argc == 6)
		info->min_eat = argv_num[5];
	else
		info->min_eat = -1;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->heads);
	pthread_mutex_init(info->forks, 0);
	info->philo = malloc(sizeof(t_philo) * info->heads);
	init_philo(info->philo, info);
	info->start = nowtime();
	info->end = FALSE;
	pthread_mutex_init(&(info->msg),0);
}

int		is_die(t_info *info)
{
	int		i;
	t_philo *p;

	p = info->philo;
	printf("");
	while (i < info->heads)
	{
		uint64_t a = nowtime();
		uint64_t b = (&p[i])->timecnt;
		if (a - b > info->die_t)
		//if (nowtime() - (&p[i])->timecnt > info->die_t)
		{
//			printf("p->num %d, %llu - %llu > %llu\n",p->num, a, b, info->die_t);
			printmsg(p, "  dead\t\t");
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int		is_full(t_info *info)
{
	int		i;
	t_philo *p;

	p = info->philo;
	i  = 0;
	if (info->min_eat == -1)
		return (FALSE);
	while (i < info->heads)
	{
		if ((&p[i])->eatcnt < info->min_eat)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	monitor(t_info *info)
{
	while (1)
	{
		if (is_full(info))
			return ;
		if (is_die(info))
			return ; 
		usleep(200);
	}
	usleep(1000);
}

int main(int argc, char *argv[])
{
	t_info	info;
	int		argv_num[6];
	int		i;

	if (argc != 5 && argc != 6)
		return (errormsg());
	i = 1;
	while (i < argc)
	{
		argv_num[i] = ft_atoi(argv[i]);
		if (argv_num[i] == -1)
			return (errormsg());
		i++;
	}
	
	init_info(argc, argv, argv_num, &info);
	i = 0;
	if (launch(&info, 0) == 0 || launch(&info, 1) == 0)
		return (1);
	monitor(&info);
	pthread_mutex_destroy(info.forks);
	printf("finish\n");

	return (1);
}
