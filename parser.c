/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:16:18 by lflorrie          #+#    #+#             */
/*   Updated: 2020/12/04 01:24:00 by lflorrie         ###   ########.fr       */
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

int	processing_int(va_list args, t_format_rule fr)
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
	if (ac == 0)
		write(1, p, len);
	else
		write(1, p, ft_strlen(p));
	if (fr.right)
		processing_width(fr, len);
	return (-1);
}

int	processing_char(va_list args, t_format_rule fr)
{
	char	ch;
	
	ch = (char)va_arg(args, int);
	if(!fr.right)
		processing_width(fr, 1);
	write(1, &ch, 1);
	if (fr.right)
		processing_width(fr, 1);
	if (fr.width != 0)
		return (fr.width);
	return (1);
}

int	processing_string(va_list args, t_format_rule fr)
{
	char	*s;
	int		len;

	if ((s = (char*)va_arg(args, int*)) == NULL)
		s = fr.accuracy >= 6 || fr.accuracy <= -1 ? "(null)" : "";
	len = (int)ft_strlen(s);
	if (fr.accuracy < len && fr.accuracy >= 0)
		len = fr.accuracy;
	if (!fr.right)
		processing_width(fr, len);
	write(1, s, len);
	if (fr.right)
		processing_width(fr, len);
	return (ft_strlen(s));
}

int	processing_pointer(va_list args, t_format_rule fr)
{
	size_t	num;
	char	*p;

	num = va_arg(args, size_t);
	p = ft_itoa16(num, 'a');
	if (num == 0)
		p = "(nil)";
	if (!fr.right)
		processing_width(fr, ft_strlen(p) + 2);
	if (num != 0)
		write(1, "0x", 2);
	write(1, p, ft_strlen(p));
	if (fr.right)
		processing_width(fr, ft_strlen(p) + 2);
	return (-1);
}

int	processing_uint(va_list args, t_format_rule fr, char flag)
{
	unsigned int	num;
	char		*p;
	int		ac;
	int		len_ac;

	num = va_arg(args, unsigned int);
	if (flag == 'u')
		p = ft_uitoa(num);
	if (flag == 'x')
		p = ft_itoa16(num, 'a');
	if (flag == 'X')
		p = ft_itoa16(num, 'A');
	ac = fr.accuracy;
	len_ac = ft_strlen(p);
	if (ac > len_ac || ac == 0)
		len_ac = ac;
	if (!fr.right)
		processing_width(fr, len_ac);
	while (ac > (int)ft_strlen(p))
	{
		--ac;
		write(1, "0", 1);
	}
	if (ac == 0)
		write(1, " ", 0);
	else
		write(1, p, ft_strlen(p));
	if (fr.right)
		processing_width(fr, len_ac);
	return (-1);
}

int	processing_flags(const char flag, va_list args, t_format_rule fr)
{
	int result;

	result = 0;
	if (flag == 'c')
	{
		result = processing_char(args, fr);
	}
	if (flag == 's')
	{
		result = processing_string(args, fr);
	}
	if (flag == 'p')
	{
		result = processing_pointer(args, fr);
	}
	if (flag == 'd' || flag == 'i')
	{
		result = processing_int(args, fr);
	}
	if (flag == '%')
	{
		write(1, "%", 1);
		result = 1;
	}
	if (flag == 'u')
	{
		result = processing_uint(args, fr, flag);
	}
	if (flag == 'x' || flag == 'X')
	{
		result = processing_uint(args, fr, flag);
	}
	return (result);
}

int	processing(const char **format, va_list args)
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
	if (**format == '*')
	{
		fr.width = (int)va_arg(args, int);
		if (fr.width < 0)
		{
			fr.right = 1;
			fr.symb = ' ';
			fr.width = -fr.width;
		}
		++*format;
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
		if (**format == '*')
		{
			fr.accuracy = (int)va_arg(args, int);
			++*format;
		}
		fr.symb = ' ';
	}
	return (processing_flags(**format, args, fr));
}
int	parser(const char *format, va_list args)
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
