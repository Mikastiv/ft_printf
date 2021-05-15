/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:07:16 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/15 17:34:11 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "do_printf.h"

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		result;

	va_start(list, format);
	result = do_printf(format, list, ft_putchar);
	va_end(list);
	return (result);
}
