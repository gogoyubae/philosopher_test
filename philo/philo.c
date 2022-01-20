/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:14:32 by yubae             #+#    #+#             */
/*   Updated: 2022/01/11 20:48:32 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_philo *p)
{
	uint64_t	start_sleeping;

	start_sleeping = nowtime();
	printmsg(p, "  is sleeping\t");
	while (nowtime() - start_sleeping < p->info->sleep_t)
		usleep(100);
}

void	thinking(t_philo *p)
{
	printmsg(p, "  is thinking\t");
}

void	eating(t_philo *p)
{
	uint64_t		start_eating;
	pthread_mutex_t	*mutex_l;
	pthread_mutex_t	*mutex_r;

	mutex_l = p->left;
	mutex_r = p->right;
	pthread_mutex_lock(mutex_l);
	printmsg(p, "  has taken a fork L");
	pthread_mutex_lock(mutex_r);
	printmsg(p, "  has taken a fork R");
	start_eating = nowtime();
	p->timecnt = start_eating;
	printmsg(p, "  is eating\t");
	while (nowtime() - start_eating < p->info->eat_t)
		usleep(100);
	p->eatcnt++;
	pthread_mutex_unlock(mutex_l);
	pthread_mutex_unlock(mutex_r);
}

void	*p_thread(void *void_philo)
{
	t_philo			*philo;

	philo = (t_philo *)void_philo;
	philo->timecnt = nowtime();
	while (!philo->info->end)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}
