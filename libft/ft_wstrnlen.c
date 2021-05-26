/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:55:51 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/25 21:56:25 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

size_t	ft_wstrnlen(const wchar_t *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (len < maxlen)
	{
		if (!s[len])
			break ;
		len++;
	}
	return (len);
}
