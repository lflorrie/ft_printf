/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 01:22:38 by lflorrie          #+#    #+#             */
/*   Updated: 2020/12/25 01:22:39 by lflorrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	processing_width(t_format_rule fr, int len)
{
	int	wid;

	wid = fr.width;
	while (wid - len > 0)
	{
		write(1, &fr.symb, 1);
		--wid;
	}
}

int		processing_flags(const char flag, va_list args, t_format_rule fr)
{
	int result;

	result = 0;
	if (flag == 'c')
		result = processing_char(args, fr);
	if (flag == 's')
		result = processing_string(args, fr);
	if (flag == 'p')
		result = processing_pointer(args, fr);
	if (flag == 'd' || flag == 'i')
		result = processing_int(args, fr);
	if (flag == '%')
	{
		write(1, "%", 1);
		result = 1;
	}
	if (flag == 'u')
		result = processing_uint(args, fr, flag);
	if (flag == 'x' || flag == 'X')
		result = processing_uint(args, fr, flag);
	return (result);
}
