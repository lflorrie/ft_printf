/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:16:18 by lflorrie          #+#    #+#             */
/*   Updated: 2020/12/21 20:28:59 by lflorrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	star(const char **format, va_list args, t_format_rule *fr)
{
	fr->width = (int)va_arg(args, int);
	if (fr->width < 0)
	{
		fr->right = 1;
		fr->symb = ' ';
		fr->width = -fr->width;
	}
	++*format;
}

void	dot(const char **format, va_list args, t_format_rule *fr)
{
	++(*format);
	fr->accuracy = 0;
	if (ft_isdigit(**format))
		fr->accuracy = ft_atoi(*format);
	while (ft_isdigit(**format))
		++*format;
	if (**format == '*')
	{
		fr->accuracy = (int)va_arg(args, int);
		++*format;
	}
	fr->symb = ' ';
}

void	minusandzero(const char **format, t_format_rule *fr)
{
	if (**format == '-')
	{
		fr->right = 1;
		++*format;
	}
	if (**format == '0')
	{
		if (!fr->right)
			fr->symb = '0';
		++*format;
	}
}

int		processing(const char **format, va_list args)
{
	t_format_rule	fr;

	fr.width = 0;
	fr.accuracy = -1;
	fr.symb = ' ';
	fr.right = 0;
	while (**format == '-' || **format == '0')
	{
		minusandzero(format, &fr);
	}
	if (**format == '*')
	{
		star(format, args, &fr);
	}
	if (ft_isdigit(**format))
	{
		fr.width = ft_atoi(*format);
		while (ft_isdigit(**format))
			++*format;
	}
	if (**format == '.')
	{
		dot(format, args, &fr);
	}
	return (processing_flags(**format, args, fr));
}

int		parser(const char *format, va_list args)
{
	int	result;

	result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			result += processing(&format, args);
		}
		else
		{
			write(1, format, 1);
			++result;
		}
		++format;
	}
	return (result);
}
