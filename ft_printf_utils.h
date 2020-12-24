/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflorrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:53:53 by lflorrie          #+#    #+#             */
/*   Updated: 2020/12/02 02:06:04 by lflorrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
#define FT_PRINTF_UTILS_H

#include <stdarg.h>
#include "libft/libft.h"
typedef struct	s_format_rule
{
				int	width;
				int	accuracy;
				char	symb;
				int	right;
}				t_format_rule;

int				parser(const char *format, va_list args);

char			*ft_itoa16(size_t nn, char flag);

char			*ft_uitoa(unsigned int nn);

void			processing_width(t_format_rule fr, int len);

int				processing_flags(const char flag, va_list args, t_format_rule fr);

int				max(int a, int b, int c);

int				processing_int(va_list args, t_format_rule fr);

int				processing_uint(va_list args, t_format_rule fr, char flag);

int				processing_char(va_list args, t_format_rule fr);

int				processing_string(va_list args, t_format_rule fr);

int				processing_pointer(va_list args, t_format_rule fr);
#endif
