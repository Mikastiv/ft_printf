/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 23:57:12 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/17 00:35:56 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_ptr.h"
#include "libft.h"
#include "utils.h"
#include "flags.h"
#include <stdlib.h>
#include <stdbool.h>

void	convert_ptr(const char **fmt, t_pinfo *info)
{
	void	*ptr;
	char	*str;
	int		len;
	bool	do_free;

	ptr = va_arg(info->va, void *);
	str = ft_ptoa_base(ptr, "0123456789abcdef");
	do_free = true;
	if (!str)
	{
		str = "0";
		do_free = false;
	}
	len = (int)ft_strlen(str) + 2;
	if (!(info->flags & F_LEFTALIGN))
		add_padding(info, &len, ' ');
	ft_putstr("0x", info);
	ft_putstr(str, info);
	if (info->flags & F_LEFTALIGN)
		add_padding(info, &len, ' ');
	if (do_free)
		free(str);
	(*fmt)++;
}
