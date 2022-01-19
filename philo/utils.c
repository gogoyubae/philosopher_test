/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:46:48 by yubae             #+#    #+#             */
/*   Updated: 2022/01/11 14:45:02 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printmsg(t_philo *p, char *str)
{
	if (p->info->end == TRUE)
		return ;
	if (pthread_mutex_lock(&(p->info->msg)) == 0)
	{
		printf("%llums\t%d%s\t[%d]\n",
			nowtime() - p->info->start, p->num, str, p->eatcnt);
		//if (p->stat != DEAD)
			pthread_mutex_unlock(&(p->info->msg));
	}
}


int	errormsg(void)
{
	printf("error!\n");
	return (1);
}

int	ft_atoi(const char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + (str[i] - '0');
			i++;
		}
		else
			return (-1);
	}
	if (res == 0)
		return (-1);
	return (res);
}

uint64_t	nowtime(void)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}
