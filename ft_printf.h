/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaquet <nmaquet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:18:47 by nmaquet           #+#    #+#             */
/*   Updated: 2023/05/04 10:18:47 by nmaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./Libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_uns_dcm(unsigned int n);
int	ft_print_str(char *s);
int	ft_print_int(int n);
int	ft_print_char(char c);
int	ft_print_hex(unsigned int num, const char format);
int	ft_print_per(void);

#endif