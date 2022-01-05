<<<<<<< HEAD
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:46:48 by yubae             #+#    #+#             */
/*   Updated: 2021/10/21 16:47:22 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 2fb58546842a9ee49de997f4fcb54beced0cb266
#include "philo.h"

int	ft_atoi(const char *str)
{
	int i;
<<<<<<< HEAD
	int flag;
	int res;

	i = 0;
	flag = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * flag);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (p1[i] && p2[i] && i < n - 1)
	{
		if (p1[i] != p2[i])
			break ;
		i++;
	}
	return (p1[i] - p2[i]);
=======
	int res;

	i = 0;
	res = 0;
	while(str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + (str[i] - '0');
			i++;
		}
		else
		{
			res = -1;
			break;
		}
	}
	if (i == 0)
		res = -1;
	return (res);
>>>>>>> 2fb58546842a9ee49de997f4fcb54beced0cb266
}
