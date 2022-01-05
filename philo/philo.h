<<<<<<< HEAD
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:37:31 by yubae             #+#    #+#             */
/*   Updated: 2021/10/21 17:33:43 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 2fb58546842a9ee49de997f4fcb54beced0cb266
#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

<<<<<<< HEAD
int	ft_atoi(const char *str);
int ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
=======
struct s_philo;

typedef struct	s_info
{
	int heads;
	uint64_t to_die;
	uint64_t to_eat;
	uint64_t to_sleep;
	pthread_mutex_t forks;
	t_philo	*philo
}				t_info;

typedef struct s_philo
{
	int num;
	int stat;
	int starve;
	int eat_cnt;
	struct s_info *info;
	pthread_mutex_t *left;
	pthread_mutex_t *right;
}				t_philo;

int	ft_atoi(char *str);

#ifndef
>>>>>>> 2fb58546842a9ee49de997f4fcb54beced0cb266
