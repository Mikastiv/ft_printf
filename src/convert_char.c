/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:26:13 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/16 23:21:05 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_char.h"
#include "flags.h"
#include "utils.h"

void	convert_char(const char **fmt, t_pinfo *info)
{
	int	padding;

	padding = 1;
	if (!(info->flags & F_LEFTALIGN))
		add_padding(info, &padding, ' ');
	info->ft_putc((char)va_arg(info->va, int));
	info->count++;
	if (info->flags & F_LEFTALIGN)
		add_padding(info, &padding, ' ');
	(*fmt)++;
}
