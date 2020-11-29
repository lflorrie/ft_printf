/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:16:18 by lflorrie          #+#    #+#             */
/*   Updated: 2020/11/30 01:58:42 by lflorrie         ###   ########.fr       */
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

void	processing_int(va_list args, t_format_rule fr)
{
	int	num;
	char	*p;
	int	ac;
	int	len;

	num = va_arg(args, int);
	p = ft_itoa(num);
	len = ft_strlen(p);
	ac = fr.accuracy;
	if (ac > len || ac == 0)
	{
		len = ac;
		if (num < 0)
			++len;
	}
	if (num < 0 && fr.symb == '0')
	{
		++p;
		write(1, "-", 1);
	}
	if (!fr.right)
		processing_width(fr, len);
	if (num < 0 && fr.symb != '0')
	{
		++p;
		write(1, "-", 1);
	}
	while (ac > (int)ft_strlen(p))
	{
		write(1, "0", 1);
		--ac;
	}
	write(1, p, ft_strlen(p));
	if (fr.right)
		processing_width(fr, len);
}

void	processing_char(va_list args, t_format_rule fr)
{
	char	ch;
	
	ch = (char)va_arg(args, int);
	if(!fr.right)
		processing_width(fr, 1);
	write(1, &ch, 1);
	if (fr.right)
		processing_width(fr, 1);
}

void	processing_string(va_list args, t_format_rule fr)
{
	char	*s;
	int		len;

	if ((s = (char*)va_arg(args, int*)) == NULL)
		s = fr.accuracy >= 6 || fr.accuracy == -1 ? "(null)" : "";
	len = (int)ft_strlen(s);
	if (fr.accuracy < len && fr.accuracy >= 0)
		len = fr.accuracy;
	if (!fr.right)
		processing_width(fr, len);
	write(1, s, len);
	if (fr.right)
		processing_width(fr, len);
}

void	processing_pointer(va_list args, t_format_rule fr)
{
	size_t	num;
	char	*p;

	num = va_arg(args, size_t);
	p = ft_itoa16(num);
	if (num == 0)
		p = "(nil)";
	if (!fr.right)
		processing_width(fr, ft_strlen(p));
	write(1, p, ft_strlen(p));
	if (fr.right)
		processing_width(fr, ft_strlen(p));
}

void	processing_flags(const char flag, va_list args, t_format_rule fr)
{
	if (flag == 'c')
	{
		processing_char(args, fr);
	}
	if (flag == 's')
	{
		processing_string(args, fr);
	}
	if (flag == 'p')
	{
		processing_pointer(args, fr);
	}
	if (flag == 'd' || flag == 'i')
	{
		processing_int(args, fr);
	}
	if (flag == '%')
	{
		write(1, "%", 1);
	}
	if (flag == 'u')
	{
		processing_int(args, fr);
	}
	if (flag == 'x' || flag == 'X')
	{
		
	}
}

void	processing(const char **format, va_list args)
{
	t_format_rule fr;

	fr.width = 0;
	fr.accuracy = -1;
	fr.symb = ' ';
	fr.right = 0;
	while (**format == '-' || **format == '0')
	{
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
	}
	if (ft_isdigit(**format))
	{
		fr.width = ft_atoi(*format);
		while (ft_isdigit(**format))
			++*format;
	}
	if (**format == '.')
	{
		++(*format);
		fr.accuracy = 0;
		if (ft_isdigit(**format))
			fr.accuracy = ft_atoi(*format);
		while(ft_isdigit(**format))
			++*format;
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
