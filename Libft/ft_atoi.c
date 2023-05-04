/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaquet <nmaquet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 06:06:58 by nmaquet           #+#    #+#             */
/*   Updated: 2023/01/14 20:36:06 by nmaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v');
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	long	res;
	long	tmp;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		tmp = res;
		res = res * 10 + (nptr[i++] - '0');
		if (res < tmp && sign == 1)
			return (-1);
		if (res < tmp && sign == -1)
			return (0);
	}
	return (sign * res);
}
