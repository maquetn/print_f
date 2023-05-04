/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_dcm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaquet <nmaquet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:32:45 by nmaquet           #+#    #+#             */
/*   Updated: 2023/05/03 18:34:30 by nmaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uilen(unsigned int str)
{
	int	len;

	len = 0;
	while (str != 0)
	{
		len++;
		str = str / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_uilen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (n != 0)
	{
		str[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

int	ft_print_uns_dcm(unsigned int n)
{
	int		print_length;
	char	*str;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		str = ft_uitoa(n);
		print_length += ft_print_str(str);
		free(str);
	}
	return (print_length);
}
