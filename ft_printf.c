/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:11:56 by lflorrie          #+#    #+#             */
/*   Updated: 2020/12/04 01:18:55 by lflorrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf_utils.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	result;

	va_start (args, format);
	result = parser(format, args);
	va_end(args);
	return (result);
}

