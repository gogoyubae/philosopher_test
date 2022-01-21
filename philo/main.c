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
	if (i % 2 == 1)
		usleep(500 * info->eat_t);
	while (i < info->heads)
	{
		pthread_create(&tid, 0, p_thread, &philo[i]);
		pthread_detach(tid);
		i += 2;
	}
	return (1);
}

void	destroy_mutex(t_info *info)
{
	pthread_mutex_destroy(info->forks);
	pthread_mutex_destroy(&info->msg);
	pthread_mutex_destroy(&info->die);
	free(info->forks);
	free(info->philo);
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
	if (init_info(argc, argv_num, &info) == FAILURE)
		return (FAILURE);
	i = 0;
	if (launch(&info, 0) == 0 || launch(&info, 1) == 0)
		return (FAILURE);
	monitor(&info);
	destroy_mutex(&info);
	return (finishmsg());
}
