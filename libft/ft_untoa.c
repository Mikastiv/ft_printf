/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_untoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:45:15 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/07 18:47:12 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_untoa(char *b, unsigned long long n, size_t len, const char *base)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	while (len > 0)
	{
		b[--len] = base[n % base_len];
		n /= base_len;
	}
}
