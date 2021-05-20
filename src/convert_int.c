/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:33:22 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/20 15:35:59 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_int.h"
#include "flags.h"
#include "libft.h"
#include "utils.h"
#include <limits.h>
#include <stdlib.h>

static char	*convert_to_str(int nb)
{
	if (nb < 0)
		return (ft_ultoa(-((long)nb)));
	return (ft_ultoa((unsigned long)nb));
}

static void	add_padding_num(t_pinfo *info, int *len, char c)
{
	int	n;

	n = *len;
	if (info->flags & F_PRECISION)
		if (*len < info->precision)
			n = info->precision;
	while (n++ < info->width)
	{
		info->ft_putc(c);
		info->count++;
		(*len)++;
	}
}

void	convert_int(const char **fmt, t_pinfo *info)
{
	char	pad_char;
	int		len;
	char	*str;
	int		nb;

	pad_char = ' ';
	if ((info->flags & F_ZEROPAD) && !(info->flags & F_PRECISION))
		pad_char = '0';
	nb = va_arg(info->va, int);
	(*fmt)++;
	if (info->flags & F_PRECISION && info->width == 0 && info->precision == 0)
		return ;
	str = convert_to_str(nb);
	if (!str)
		return ;
	len = 0;
	if (nb < 0)
		len++;
	len += ft_strnlen(str, INT_MAX - len);
	if (nb < 0 && pad_char == '0' && !(info->flags & F_LEFTALIGN))
		ft_putstr("-", info);
	if (!(info->flags & F_LEFTALIGN))
		add_padding_num(info, &len, pad_char);
	if (nb < 0 && pad_char != '0')
		ft_putstr("-", info);
	info->precision -= ft_strnlen(str, INT_MAX - len);
	if (info->flags & F_PRECISION)
		while (info->precision && info->precision-- > len && ++info->count)
			info->ft_putc('0');
	ft_putstr(str, info);
	if (info->flags & F_LEFTALIGN)
		add_padding(info, &len, ' ');
	free(str);
}
