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

void	init_philo(t_philo *philo, t_info *info)
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
		}
		else
		{
			tmp->left = &info->forks[num];
			tmp->right = &info->forks[num + 1];
		}
		num++;
	}
	return ;
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
	if (malloc_info(info) == FAILURE)
		return (FAILURE);
	if (init_mutex(info) == FAILURE)
		return (FAILURE);
	init_philo(info->philo, info);
	info->start = nowtime();
	info->end = FALSE;
	return (TRUE);
}
