/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:26:13 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/25 22:53:07 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_char.h"
#include "flags.h"
#include "utils.h"
#include "libft.h"

bool	convert_char(t_pinfo *info, wint_t c)
{
	int		padding;
	char	pad_char;

	pad_char = get_pad_char(info);
	if (info->flags & F_LONG)
		padding = ft_wchar_size(c);
	else
		padding = 1;
	if (!(info->flags & F_LEFTALIGN))
		add_padding(info, &padding, pad_char);
	if (info->flags & F_LONG)
		info->count += info->ft_putwc(c);
	else
		info->count += info->ft_putc((char)c);
	if (info->flags & F_LEFTALIGN)
		add_padding(info, &padding, pad_char);
	return (true);
}
