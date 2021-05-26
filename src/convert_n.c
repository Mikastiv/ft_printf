/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:10:53 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/26 18:13:43 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_n.h"
#include "flags.h"

bool	convert_n(t_pinfo *info)
{
	int		*i_ptr;
	long	*l_ptr;

	if (info->flags & F_LONG)
	{
		l_ptr = va_arg(info->va, long *);
		*l_ptr = (long)info->count;
	}
	else
	{
		i_ptr = va_arg(info->va, int *);
		*i_ptr = info->count;
	}
	return (true);
}
