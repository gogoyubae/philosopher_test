<<<<<<< HEAD
#include "philo.h"

typedef struct	s_info
{
	int heads;
	int die_t;
	int eat_t;
	int sleep_t;
	int	min_eat;
}				t_info;
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:14:32 by yubae             #+#    #+#             */
/*   Updated: 2021/10/21 17:36:21 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 2fb58546842a9ee49de997f4fcb54beced0cb266

int main(int argc, char *argv[])
{
	t_info	*info;
	int		i;

<<<<<<< HEAD
	if (argc != 5 && argc != 6)
	{
		printf("error\n");
		return (1);
	}
	i = 1;
	while (i < 5)
	{
		if (!ft_strncmp(argv[i], "0", 2))
		{	
			printf("error\n");
			return (1);
		}
		i++;
	}
	info->heads = ft_atoi(argv[1]);
	info->die_t = ft_atoi(argv[2]);
	info->eat_t = ft_atoi(argv[3]);
	info->sleep_t = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (!ft_strncmp(argv[5], "0", 2))
		{	
			printf("error\n");
			return (1);
		}
		info->min_eat = ft_atoi(argv[5]);
	}
=======
	info->heads = ft_atoi(argv[1]);
	info->to_die = ft_atoi(argv[2]);
	info->to_eat = ft_atoi(argv[3]);
	info->to_sleep = ft_atoi(argv[4]);
	if (argc != 6)
	{
		info->

	eat(&info);
>>>>>>> 2fb58546842a9ee49de997f4fcb54beced0cb266
}

void eat(t_info *info)
{

}

