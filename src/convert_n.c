/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:10:53 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/26 19:37:32 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_n.h"
#include "flags.h"

static void	long_ptr(t_pinfo *info)
{
	long		*l_ptr;
	long long	*ll_ptr;

	if (info->flags & F_LONG_LONG)
	{
		ll_ptr = va_arg(info->va, long long *);
		*ll_ptr = (long long)info->count;
	}
	else if (info->flags & F_LONG)
	{
		l_ptr = va_arg(info->va, long *);
		*l_ptr = (long)info->count;
	}
}

static void	half_ptr(t_pinfo *info)
{
	short	*h_ptr;
	char	*hh_ptr;

	if (info->flags & F_HALF_HALF)
	{
		hh_ptr = va_arg(info->va, char *);
		*hh_ptr = (char)info->count;
	}
	else if (info->flags & F_HALF)
	{
		h_ptr = va_arg(info->va, short *);
		*h_ptr = (short)info->count;
	}
}

bool	convert_n(t_pinfo *info)
{
	int			*i_ptr;

	if (info->flags & (F_LONG_LONG | F_LONG))
		long_ptr(info);
	else if (info->flags & (F_HALF_HALF | F_HALF))
		half_ptr(info);
	else
	{
		i_ptr = va_arg(info->va, int *);
		*i_ptr = (int)info->count;
	}
	return (true);
}
