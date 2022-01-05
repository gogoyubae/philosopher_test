/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:14:32 by yubae             #+#    #+#             */
/*   Updated: 2022/01/05 20:41:33 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int errormsg(void)
{
	printf("error!\n");
	return (1);
}

int	pthread_heads(int num)
{


}

void init_info(int argc, char *argv[], int *argv_num, t_info *info)
{
	info->heads = argv_num[1];
	info->die_t = argv_num[2];
	info->eat_t = argv_num[3];
	info->sleep_t = argv_num[4];
	if (argc == 6)
		info->min_eat = argv_num[5];
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
	i = 1;
	while (i < argc)
	{
		printf("argv_num[%d]: %d\n", i, argv_num[i]);
		i++;
	}
	
	int i = 0;
	pthread_t tid;
	while (i < info.heads)
	{
		pthread_create(&tid, 0, pthread_heads, info);
		i++;
	}

	return (1);
}
