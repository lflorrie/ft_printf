/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:16:18 by lflorrie          #+#    #+#             */
/*   Updated: 2020/11/27 13:02:58 by lflorrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

typedef struct	s_format_rule
{
		int	width;
		int	accuracy;
		char	symb;
		int	right;
}		t_format_rule;

void	processing_flags(const char flag, va_list args, t_format_rule fr)
{
	if (flag == 'c')
	{
		char a = (char)va_arg(args, int);
		write(1, &a, 1);
	}
	if (flag == 's')
	{
		char  *s = (char*)va_arg(args, int*);
		write(1, s, ft_strlen(s));
	}
	if (flag == 'p')
	{
		size_t num;
		num = va_arg(args, size_t);
		char *p = ft_itoa16(num);
		write(1, p, ft_strlen(p));
	}
	if (flag == 'd' || flag == 'i')
	{
		int num;
		num = va_arg(args, int);
		char *p = ft_itoa(num);

		int ac = fr.accuracy - (int)ft_strlen(p);
		int wid = fr.width;
		if (ac > 0)
			wid -= ac;
		while (wid - (int)ft_strlen(p) > 0 && !fr.right)
		{
			write(1, &fr.symb, 1);
			--wid;
		}
		while (ac > 0 && !fr.right)
		{
			write(1, "0", 1);
			--ac;
		}
		write(1, p, ft_strlen(p));
		while (wid - (int)ft_strlen(p) > 0 && fr.right)
		{
			write(1, &fr.symb, 1);
			--wid;
		}
	}
	if (flag == '%')
	{
		write(1, "%", 1);
	}
	if (flag == 'u')
	{
		
	}
	if (flag == 'x' || flag == 'X')
	{
		
	}
}

void	processing(const char **format, va_list args)
{
	t_format_rule fr;

	fr.width = 0;
	fr.accuracy = 0;
	fr.symb = ' ';
	fr.right = 0;
	if (**format == '-')
	{
		fr.right = 1;
		++*format;
	}
	if (**format == '0')
	{
		if (!fr.right)
			fr.symb = '0';
		++*format;
	}
	if (ft_isdigit(**format))
	{
		fr.width = **format - '0';
		++*format;
	}
	if (**format == '.')
	{
		++(*format);
		if (ft_isdigit(**format))
			fr.accuracy = **format - '0';
		++(*format);
		fr.symb = ' ';
	}
	processing_flags(**format, args, fr);

}
void	parser(const char *format, va_list args)
{
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			processing(&format, args);
		}
		else
			write(1, format, 1);
		++format;
	}
}
