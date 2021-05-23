/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:26:13 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/23 11:09:52 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_char.h"
#include "flags.h"
#include "utils.h"
#include "libft.h"

bool	convert_char(t_pinfo *info, char c)
{
	int		padding;
	char	pad_char;

	pad_char = get_pad_char(info);
	padding = 1;
	if (!(info->flags & F_LEFTALIGN))
		add_padding(info, &padding, pad_char);
	if (ft_isascii(c))
		info->ft_putc(c);
	else
		info->ft_putc('?');
	info->count++;
	if (info->flags & F_LEFTALIGN)
		add_padding(info, &padding, pad_char);
	return (true);
}
