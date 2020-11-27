/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 23:08:27 by lflorrie          #+#    #+#             */
/*   Updated: 2020/11/23 23:30:30 by lflorrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

static size_t	len(size_t n)
{
	int	i;

	i = 1;
	n = n / 16;
	while (n != 0)
	{
		++i;
		n = n / 16;
	}
	return (i);
}

char			*ft_itoa16(size_t nn)
{
	char		*result;
	size_t		i;
	size_t	n;

	n = nn;
	i = len(n) + 2;
	if (!(result = (char*)malloc((i) * sizeof(char) + 1)))
		return (NULL);
	result[0] = '0';
	result[1] = 'x';
	result[i] = '\0';
	while (i > 2)
	{
		
		size_t temp = (n % 16) > 9 ? ('a' - 10) : '0';
		result[--i] = (char)(n % 16 + temp);
		n /= 16;
	}
	return (result);
}
