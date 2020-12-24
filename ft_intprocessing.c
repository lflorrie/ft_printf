/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intprocessing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:31:38 by lflorrie          #+#    #+#             */
/*   Updated: 2020/12/24 18:32:32 by lflorrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int		max(int a, int b, int c)
{
	int result;

	if (a > b)
		result = a;
	else
		result = b;
	if (c > result)
		result = c;
	return (result);
}

void	print_num(char *p, int len, t_format_rule fr)
{
	int		ac;

	if (*p == '-' && fr.symb == '0')
	{
		write(1, p++, 1);
	}
	if (!fr.right)
		processing_width(fr, len);
	if (*p == '-' && fr.symb != '0')
	{
		write(1, p++, 1);
	}
	ac = fr.accuracy;
	while (ac > (int)ft_strlen(p))
	{
		--ac;
		write(1, "0", 1);
	}
	if (ac == 0 && *p == '0')
		write(1, "", 0);
	else
		write(1, p, ft_strlen(p));
	if (fr.right)
		processing_width(fr, len);
}

int		processing_int(va_list args, t_format_rule fr)
{
	int		num;
	char	*p;
	int		ac;
	int		len;

	num = va_arg(args, int);
	p = ft_itoa(num);
	len = ft_strlen(p);
	ac = fr.accuracy;
	if (ac > len || (ac == 0 && *p == '0'))
	{
		len = ac;
		if (num < 0)
			++len;
	}
	print_num(p, len, fr);
	return (max(fr.width, fr.accuracy, len));
}

int		processing_uint(va_list args, t_format_rule fr, char flag)
{
	unsigned int	num;
	char			*p;
	int				len_ac;

	num = va_arg(args, unsigned int);
	if (flag == 'u')
		p = ft_uitoa(num);
	if (flag == 'x')
		p = ft_itoa16(num, 'a');
	if (flag == 'X')
		p = ft_itoa16(num, 'A');
	len_ac = ft_strlen(p);
	if (fr.accuracy > len_ac || (fr.accuracy == 0 && *p == '0'))
		len_ac = fr.accuracy;
	print_num(p, len_ac, fr);
	return (max(fr.width, fr.accuracy, len_ac));
}
