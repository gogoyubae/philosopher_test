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

int     launch(t_philo *philo)
{
	int	i;
	
	i = 0;
	while (i < philo->info->heads)
	{
		printf("\n");
		init_fork(&philo[i], i, philo->info);
		i++;
	}
    return (1);
}
int     init_fork(t_philo *philo, int num, t_info *info)
{
   // t_info      *info;
	pthread_t	tid;

    //info = philo->info;
	philo->num = num + 1;
    if (num + 1 == info->heads)
    {
        philo->left = &info->forks[num];
        philo->right = &info->forks[0];
        printf("left %d right %d\n",num, 0);
    }
    else
    {
        philo->left = &info->forks[num];
        philo->right = &info->forks[num + 1];
        printf("left %d right %d\n",num, num + 1);
    }
    pthread_create(&tid, 0, p_thread, philo);
    pthread_join(tid, 0);
    return (1);
}


void init_info(int argc, char *argv[], int *argv_num, t_info *info)
{
	info->heads = argv_num[1];
	info->die_t = argv_num[2];
	info->eat_t = argv_num[3];
	info->sleep_t = argv_num[4];
	if (argc == 6)
		info->min_eat = argv_num[5];
	info->forks = malloc(sizeof(pthread_mutex_t) * info->heads);
	pthread_mutex_init(info->forks, 0);

}

int main(int argc, char *argv[])
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
	
	init_info(argc, argv, argv_num, &info);
	
	t_philo *philo;
	philo = malloc(sizeof(t_philo) * info.heads);

	philo->info = &info;
	launch(philo);
	pthread_mutex_destroy(info.forks);

	return (1);
}
