/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:39:52 by lflorrie          #+#    #+#             */
/*   Updated: 2020/12/02 00:36:07 by lflorrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static size_t	len(unsigned int n)
{
	int	i;

	i = 1;
	n = n / 10;
	while (n != 0)
	{
		++i;
		n = n / 10;
	}
	return (i);
}

char			*ft_uitoa(unsigned int n)
{
	char		*result;
	size_t		i;

	i = len(n);
	if (!(result = (char*)malloc((i + 1) * sizeof(char))))
		return (NULL);
	result[i] = '\0';
	while (i > 0)
	{
		result[--i] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (result);
}
