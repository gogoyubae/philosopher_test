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
	printf("%d is sleeping\n", p->num);
	while (nowtime() - start_sleeping < p->info->sleep_t)
		usleep(100);
}

void	eating(t_philo *p)
{
	pthread_mutex_t	*mutex_l;
	pthread_mutex_t	*mutex_r;

	mutex_l = p->left;
	mutex_r = p->right;
	pthread_mutex_lock(mutex_l);
	pthread_mutex_lock(mutex_r);
	
	uint64_t	start_eating;

	start_eating = nowtime();
	printf("%d is eating\n", p->num);
	 printf("%llu is p->info->eat_t\n", p->info->eat_t);

	while (nowtime() - start_eating < p->info->eat_t)
		usleep(100);
	
	pthread_mutex_unlock(mutex_l);
	pthread_mutex_unlock(mutex_r);

}

void	*p_thread(void *void_philo)
{
	t_philo			*philo;
// 	t_info			*info;

	philo = (t_philo *)void_philo;
	eating(philo);
	sleeping(philo);
	printf("philo->num %d eat sleep end------\n", philo->num);
	return (0);
}
