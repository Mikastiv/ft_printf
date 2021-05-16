/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:36:48 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/15 20:15:09 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_printf.h"
#include "flags.h"
#include "libft.h"
#include <stdbool.h>

static unsigned int	get_flags(const char **fmt)
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

static int	get_width(const char **fmt, va_list va, unsigned int *flags)
{
	int	width;
	int	arg;

	width = 0;
	if (ft_isdigit(**fmt))
		while (ft_isdigit(**fmt))
			width = width * 10 + (*((*fmt)++) - '0');
	else if (**fmt == '*')
	{
		arg = va_arg(va, int);
		if (arg < 0)
		{
			*flags |= F_LEFTALIGN;
			width = -arg;
		}
		else
			width = arg;
		(*fmt)++;
	}
	return (width);
}

int	do_printf(const char *fmt, va_list va, void (*ft_putc)(char))
{
	int				count;
	unsigned int	flags;
	int				width;

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
	ft_putnbr_fd(flags, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(width, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(va_arg(va, int), 2);
	ft_putchar_fd('\n', 2);
	return (count);
}
