/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointerprocessing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:42:37 by lflorrie          #+#    #+#             */
/*   Updated: 2020/12/24 18:42:39 by lflorrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int		processing_pointer(va_list args, t_format_rule fr)
{
	size_t	num;
	char	*p;
	int		len;

	num = va_arg(args, size_t);
	p = ft_itoa16(num, 'a');
	len = ft_strlen(p) + 2;
	if (num == 0)
	{
		p = "(nil)";
		len = 5;
	}
	if (fr.width > len)
		len = fr.width;
	if (!fr.right)
		processing_width(fr, ft_strlen(p) + 2);
	if (num != 0)
		write(1, "0x", 2);
	write(1, p, ft_strlen(p));
	if (fr.right)
		processing_width(fr, ft_strlen(p) + 2);
	return (len);
}
