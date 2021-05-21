/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:33:22 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/21 14:15:49 by mleblanc         ###   ########.fr       */
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

static void	add_num_padding(t_pinfo *info, char c)
{
	while (info->width-- > 0)
	{
		info->ft_putc(c);
		info->count++;
	}
}

static void	calculate_len(t_pinfo *info, int *len, int nb, char *str)
{
	*len = ft_strnlen(str, INT_MAX);
	info->width -= *len;
	info->precision -= *len;
	if (info->flags & F_PRECISION && info->precision > 0)
		info->width -= info->precision;
	if (nb < 0)
		info->width--;
}

static void	print_number(t_pinfo *info, char *str, int nb, char pad_char)
{
	if (nb < 0 && pad_char == '0')
		ft_putstr("-", info);
	if (!(info->flags & F_LEFTALIGN))
		add_num_padding(info, pad_char);
	if (nb < 0 && pad_char == ' ')
		ft_putstr("-", info);
	if (info->flags & F_PRECISION)
		while (info->precision && info->precision-- > 0 && ++info->count)
			info->ft_putc('0');
	ft_putstr(str, info);
	if (info->flags & F_LEFTALIGN)
		add_num_padding(info, ' ');
}

void	convert_int(const char **fmt, t_pinfo *info)
{
	char	pad_char;
	int		len;
	char	*str;
	int		nb;

	(*fmt)++;
	pad_char = ' ';
	if ((info->flags & F_ZEROPAD) && !(info->flags & F_PRECISION))
		pad_char = '0';
	nb = va_arg(info->va, int);
	if (nb == 0 && info->flags & F_PRECISION && info->precision == 0)
		add_num_padding(info, ' ');
	str = convert_to_str(nb);
	if (!str || (nb == 0 && info->flags & F_PRECISION && info->precision == 0))
		return ;
	calculate_len(info, &len, nb, str);
	print_number(info, str, nb, pad_char);
	free(str);
}
