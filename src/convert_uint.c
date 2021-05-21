/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:53:44 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/21 19:08:56 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_uint.h"
#include "flags.h"
#include "libft.h"
#include "utils.h"
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

static void	print_number(t_pinfo *info, char *str, char pad_char)
{
	if (!(info->flags & F_LEFTALIGN))
		add_num_padding(info, pad_char);
	if (info->flags & F_PRECISION)
		while (info->precision && info->precision-- > 0 && ++info->count)
			info->ft_putc('0');
	ft_putstr(str, info);
	if (info->flags & F_LEFTALIGN)
		add_num_padding(info, ' ');
}

void	convert_uint(const char **fmt, t_pinfo *info)
{
	char			pad_char;
	char			*str;
	unsigned int	nb;
	bool			precision_is_0;

	(*fmt)++;
	pad_char = ' ';
	if (info->flags & F_PRECISION)
		info->flags &= ~F_ZEROPAD;
	precision_is_0 = (info->flags & F_PRECISION) && (info->precision == 0);
	if (info->flags & F_ZEROPAD)
		pad_char = '0';
	nb = va_arg(info->va, unsigned int);
	if (nb == 0 && precision_is_0)
		add_num_padding(info, ' ');
	str = ft_utoa(nb);
	if (!str || (nb == 0 && precision_is_0))
		return ;
	calculate_padding(info, str);
	print_number(info, str, pad_char);
	free(str);
}
