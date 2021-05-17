/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:16:52 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/17 15:30:27 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_percent.h"
#include "flags.h"
#include "utils.h"

void	convert_percent(const char **fmt, t_pinfo *info)
{
	int		padding;
	char	pad_char;

	padding = 1;
	pad_char = ' ';
	if (info->flags & F_ZEROPAD)
		pad_char = '0';
	if (!(info->flags & F_LEFTALIGN))
		add_padding(info, &padding, pad_char);
	info->ft_putc('%');
	info->count++;
	if (info->flags & F_LEFTALIGN)
		add_padding(info, &padding, pad_char);
	(*fmt)++;
}
