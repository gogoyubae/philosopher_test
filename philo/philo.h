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

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

# define	FALSE	0
# define	TRUE	1

# define	FAILURE 0
# define	SUCCESS 1

struct	s_philo;

typedef struct s_info
{
	int				heads;
	uint64_t		die_t;
	uint64_t		eat_t;
	uint64_t		sleep_t;
	int				min_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg;
	pthread_mutex_t	die;
	struct s_philo	*philo;
	uint64_t		start;
	int				end;
}					t_info;

typedef struct s_philo
{
	int				num;
	int				eatcnt;
	uint64_t		timecnt;
	struct s_info	*info;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}					t_philo;

/* init.c */
int			init_info(int argc, int *argv_num, t_info *info);

/* monitor.c */
void		monitor(t_info *info);

/* philo.c */
void		*p_thread(void *void_philo);

/* utils.c */
void		printmsg(t_philo *p, char *str);
int			finishmsg(void);
int			errormsg(void);
int			ft_atoi(const char *str);
uint64_t	nowtime(void);

#endif
