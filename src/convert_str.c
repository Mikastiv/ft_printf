/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:45:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/25 22:07:43 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_str.h"
#include "flags.h"
#include "libft.h"
#include "utils.h"
#include <limits.h>
#include <wchar.h>

#define NULL_STR "(null)"
#define NULL_WSTR L"(null)"

static int	extra_space(const wchar_t *s, int precision, bool has_prec_flag)
{
	while (has_prec_flag && *s && (int)ft_wchar_size(*s) <= precision)
	{
		precision -= (int)ft_wchar_size(*s);
		s++;
	}
	if (has_prec_flag)
		return (precision);
	return (0);
}

static bool	convert_wstr(t_pinfo *info)
{
	wchar_t	*str;
	int		len;
	int		extra;

	str = va_arg(info->va, wchar_t *);
	if (!str)
		str = NULL_WSTR;
	len = ft_wstrnlen(str, (size_t)info->precision);
	extra = extra_space(str, info->precision, info->flags & F_PRECISION);
	if (!(info->flags & F_LEFTALIGN))
		add_padding(info, &len, ' ');
	if (!(info->flags & F_LEFTALIGN))
		while (extra--)
			info->count += info->ft_putc(' ');
	while (*str && (int)ft_wchar_size(*str) <= info->precision)
	{
		info->precision -= ft_wchar_size(*str);
		info->count += info->ft_putwc(*str++);
	}
	if (info->flags & F_LEFTALIGN)
		add_padding(info, &len, ' ');
	if (info->flags & F_LEFTALIGN)
		while (extra--)
			info->count += info->ft_putc(' ');
	return (true);
}

bool	convert_str(t_pinfo *info)
{
	const char	*str;
	int			len;

	if (!(info->flags & F_PRECISION))
		info->precision = INT_MAX;
	if (info->flags & F_LONG)
		return (convert_wstr(info));
	str = va_arg(info->va, char *);
	if (!str)
		str = NULL_STR;
	len = (int)ft_strnlen(str, (size_t)info->precision);
	if (!(info->flags & F_LEFTALIGN))
		add_padding(info, &len, ' ');
	while (*str && info->precision--)
		info->count += info->ft_putc(*str++);
	if (info->flags & F_LEFTALIGN)
		add_padding(info, &len, ' ');
	return (true);
}
