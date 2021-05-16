/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:45:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/16 19:24:39 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_str.h"
#include "flags.h"
#include "libft.h"
#include <limits.h>

#define NULL_STR "(null)"

void	convert_str(const char **fmt, t_pinfo *info, void (*ft_putc)(char))
{
	const char	*str;
	int			len;

	if (!(info->flags & F_PRECISION))
		info->precision = INT_MAX;
	str = va_arg(info->va, char *);
	if (!str && info->precision > 5)
		str = NULL_STR;
	else if (!str)
		str = "";
	len = (int)ft_strnlen(str, (size_t)info->precision);
	if (!(info->flags & F_LEFTALIGN))
		while (len++ < info->width)
		{
			ft_putc(' ');
			info->count++;
		}
	while (*str && (!(info->flags & F_PRECISION) || info->precision--))
	{
		ft_putc(*str++);
		info->count++;
	}
	if (info->flags & F_LEFTALIGN)
		while (len++ < info->width)
		{
			ft_putc(' ');
			info->count++;
		}
	(*fmt)++;
}
