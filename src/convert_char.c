/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:26:13 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/16 14:52:32 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_char.h"
#include "flags.h"
#include <stdarg.h>

void	convert_char(const char **fmt, t_pinfo *info, void (*ft_putc)(char))
{
	int	padding;

	padding = 1;
	if (!(info->flags & F_LEFTALIGN))
	{
		while (padding++ < info->width)
		{
			ft_putc(' ');
			info->count++;
		}
	}
	ft_putc((char)va_arg(info->va, int));
	info->count++;
	if (info->flags & F_LEFTALIGN)
	{
		while (padding++ < info->width)
		{
			ft_putc(' ');
			info->count++;
		}
	}
	(*fmt)++;
}
