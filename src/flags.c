/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:31:51 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/15 16:38:52 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include <stdbool.h>

unsigned int	get_flags(const char **fmt)
{
	unsigned int	flags;

	flags = 0U;
	while (true)
	{
		if (**fmt == '0')
			flags |= F_ZEROPAD;
		else if (**fmt == '-')
			flags |= F_LEFTALIGN;
		else
			break ;
		(*fmt)++;
	}
	return (flags);
}
