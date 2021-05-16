/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:45:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/16 18:30:49 by mleblanc         ###   ########.fr       */
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
	size_t		len;

	if (!(info->flags & F_PRECISION))
		info->precision = INT_MAX;
	str = va_arg(info->va, char *);
	len = ft_strnlen(str, (size_t)info->precision);
	(void)fmt;
	(void)ft_putc;
}
