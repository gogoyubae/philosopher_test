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

int	launch(t_info *info, int i)
{
	pthread_t	tid;
	t_philo		*philo;

	philo = info->philo;
	if (i % 2 == 0)
		usleep(500 * info->eat_t);
	while (i < info->heads)
	{
		pthread_create(&tid, 0, p_thread, &philo[i]);
		pthread_detach(tid);
		i += 2;
	}
	return (1);
}

int	init_philo(t_philo *philo, t_info *info)
{
	int		num;
	t_philo	*tmp;

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
	//		printf("left %d right %d\n",num, 0);
	    }
		else
		{
			tmp->left = &info->forks[num];
			tmp->right = &info->forks[num + 1];
	//		printf("left %d right %d\n",num, num + 1);
	    }
		num++;
	}
    return (1);
}

int	init_mutex(t_info *info)
{
	if (pthread_mutex_init(info->forks, 0) == -1)
		return (FAILURE);
	if (pthread_mutex_init(&(info->msg), 0) == -1)
		return (FAILURE);
	if (pthread_mutex_init(&(info->die), 0) == -1)
		return (FAILURE);
	return (SUCCESS);
}
int	malloc_info(t_info *info)
{
	info->forks = malloc(sizeof(pthread_mutex_t) * info->heads);
	if (info->forks == FAILURE)
		return (FAILURE);
	info->philo = malloc(sizeof(t_philo) * info->heads);
	if (info->philo == FAILURE)
	{
		free(info->forks);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	init_info(int argc, char *argv[], int *argv_num, t_info *info)
{
	info->heads = argv_num[1];
	info->die_t = argv_num[2];
	info->eat_t = argv_num[3];
	info->sleep_t = argv_num[4];
	if (argc == 6)
		info->min_eat = argv_num[5];
	else
		info->min_eat = -1;
//	info->forks = malloc(sizeof(pthread_mutex_t) * info->heads);
//	info->philo = malloc(sizeof(t_philo) * info->heads);
	if (malloc_info(info) == FAILURE)
		return (FAILURE);
	if (init_mutex(info) == FAILURE)
		return (FAILURE);
	init_philo(info->philo, info);
	info->start = nowtime();
	info->end = FALSE;
	return (TRUE);
}


int	main(int argc, char *argv[])
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
	if (init_info(argc, argv, argv_num, &info) == FAILURE)
		return (FAILURE);
	i = 0;
	if (launch(&info, 0) == 0 || launch(&info, 1) == 0)
		return (FAILURE);
	monitor(&info);
	pthread_mutex_destroy(info.forks);
	printf("finish\n");
	return (SUCCESS);
}
