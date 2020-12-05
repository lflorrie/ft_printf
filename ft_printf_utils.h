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
int	parser(const char *format, va_list args);

char	*ft_itoa16(size_t nn, char flag);

char	*ft_uitoa(unsigned int nn);
#endif
