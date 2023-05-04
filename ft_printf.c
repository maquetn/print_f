/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaquet <nmaquet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:54:58 by nmaquet           #+#    #+#             */
/*   Updated: 2023/05/04 15:38:55 by nmaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list args, const char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_print_char(va_arg(args, int));
	if (format == 's')
		i += ft_print_str(va_arg(args, char *));
	if (format == 'p')
		i += ft_print_ptr(va_arg(args, unsigned long long));
	if (format == 'd' || format == 'i')
		i += ft_print_int(va_arg(args, int));
	if (format == 'u')
		i += ft_print_uns_dcm(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		i += ft_print_hex(va_arg(args, unsigned int), format);
	if (format == '%')
		i += ft_print_per();
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	int		k;
	va_list	args;

	i = 0;
	j = 0;
	k = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			k = i;
			j += check_format(args, str[i + 1]);
			if (i < k)
				return(-1);
			i++;
		}
		else
			j += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (j);
}
