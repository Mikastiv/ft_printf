/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:07:16 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/25 01:37:11 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_printf.h"
#include "libft.h"
#include <unistd.h>

static void	ft_putchar(unsigned char c)
{
	write(1, &c, sizeof(unsigned char));
}

int	ft_printf(const char *format, ...)
{
	t_pinfo	info;
	int		result;

	if (!format)
		return (-1);
	info = (t_pinfo){};
	va_start(info.va, format);
	info.ft_putc = ft_putchar;
	result = do_printf(format, &info);
	va_end(info.va);
	return (result);
}
