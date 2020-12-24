/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 23:08:27 by lflorrie          #+#    #+#             */
/*   Updated: 2020/12/02 01:01:09 by lflorrie         ###   ########.fr       */
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

char			*ft_itoa16(size_t nn, char flag)
{
	char		*result;
	size_t		i;
	size_t		n;
	size_t		temp;

	n = nn;
	i = len(n);
	if (!(result = (char*)malloc((i) * sizeof(char) + 1)))
		return (NULL);
	result[i] = '\0';
	while (i > 0)
	{
		temp = (n % 16) > 9 ? (flag - 10) : '0';
		result[--i] = (char)(n % 16 + temp);
		n /= 16;
	}
	return (result);
}
