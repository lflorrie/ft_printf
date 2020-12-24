/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charprocessing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:38:16 by lflorrie          #+#    #+#             */
/*   Updated: 2020/12/24 18:38:21 by lflorrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int		processing_char(va_list args, t_format_rule fr)
{
	char	ch;

	ch = (char)va_arg(args, int);
	if (!fr.right)
		processing_width(fr, 1);
	write(1, &ch, 1);
	if (fr.right)
		processing_width(fr, 1);
	if (fr.width != 0)
		return (fr.width);
	return (1);
}

int		processing_string(va_list args, t_format_rule fr)
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
	if (len < fr.width)
		len = fr.width;
	return (len);
}
