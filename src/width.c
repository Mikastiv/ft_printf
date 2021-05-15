/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:11:02 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/15 17:34:33 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "width.h"
#include "flags.h"
#include "libft.h"

unsigned int	get_width(const char **fmt, va_list va, unsigned int *flags)
{
	unsigned int	width;
	int				arg;
	va_list			copy;

	width = 0U;
	if (ft_isdigit(**fmt))
		while (ft_isdigit(**fmt))
			width = width * 10U + (unsigned int)(*((*fmt)++) - '0');
	else if (**fmt == '*')
	{
		va_copy(copy, va);
		arg = va_arg(copy, int);
		if (arg < 0)
		{
			*flags |= F_LEFTALIGN;
			width = (unsigned int)(-arg);
		}
		else
			width = (unsigned int)arg;
		va_end(copy);
		(*fmt)++;
	}
	return (width);
}
