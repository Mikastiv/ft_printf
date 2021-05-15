/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:36:48 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/14 22:14:46 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_printf.h"

int	do_printf(const char *fmt, va_list va, void (*ft_putc)(char))
{
	int	count;

	(void)va;
	count = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_putc(*fmt++);
			count++;
			continue ;
		}
	}
	return (0);
}
