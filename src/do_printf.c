/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:36:48 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/15 17:34:04 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_printf.h"
#include "flags.h"
#include "width.h"
#include "libft.h"

int	do_printf(const char *fmt, va_list va, void (*ft_putc)(char))
{
	int				count;
	unsigned int	flags;
	unsigned int	width;

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
		fmt++;
		flags = get_flags(&fmt);
		width = get_width(&fmt, va, &flags);
	}
	ft_putnbr_fd(flags, 1);
	ft_putc('\n');
	ft_putnbr_fd(width, 1);
	ft_putc('\n');
	return (count);
}
