/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:37:31 by yubae             #+#    #+#             */
/*   Updated: 2022/01/11 17:42:52 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

struct s_philo;

typedef struct		s_info
{
	int				heads;
	uint64_t		die_t;
	uint64_t		eat_t;
	uint64_t		sleep_t;
	int				min_eat;
	pthread_mutex_t	*forks;
	struct s_philo	*philo;
}					t_info;

typedef struct		s_philo
{
	int				num;
	//int				stat;
	int				timecnt;
	int				eatcnt;
	struct s_info	*info;
	pthread_mutex_t *left;
	pthread_mutex_t *right;
}					t_philo;

/* utils.c */
int	errormsg(void);
int	ft_atoi(const char *str);
uint64_t nowtime(void);

/* philo.c */
int	init_philo(t_philo *philo, t_info *info);
void *p_thread(void *void_philo);
#endif
