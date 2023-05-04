/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaquet <nmaquet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 06:11:16 by nmaquet           #+#    #+#             */
/*   Updated: 2022/12/16 07:16:14 by nmaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	j = 0;
	while (j < len && haystack[j])
	{
		i = 0;
		while (j < len && needle[i] && haystack[j] && needle[i] == haystack[j])
		{
			++i;
			++j;
		}
		if (needle[i] == '\0')
			return ((char *)&haystack[j - i]);
		j = j - i + 1;
	}
	return (0);
}
