/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:14:32 by yubae             #+#    #+#             */
/*   Updated: 2022/01/11 20:48:32 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_die(t_info *info)
{
	int		i;
	t_philo	*p;

	p = info->philo;
	while (i < info->heads)
	{
		usleep(100);
		if (nowtime() - (&p[i])->timecnt > info->die_t)
		{
			pthread_mutex_lock(&info->die);
			printmsg(p, "  dead\t\t");
			pthread_mutex_unlock(&info->die);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int	is_full(t_info *info)
{
	int		i;
	t_philo	*p;

	p = info->philo;
	i = 0;
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
