/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:34:42 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/26 18:36:11 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(long long num, long long base)
{
	size_t	len;

	len = 0;
	while (num / base != 0)
	{
		num /= base;
		len++;
	}
	return (len + 1);
}

static void	ft_ntoa(char *buf, long long n, const char *base, size_t len)
{
	long long	base_len;
	long long	i;

	base_len = ft_strlen(base);
	if (n < 0)
		*buf++ = '-';
	while (len > 0)
	{
		i = n % base_len;
		if (i < 0)
			i *= -1;
		buf[--len] = base[i];
		n /= base_len;
	}
}

char	*ft_lltoa_base(long long n, const char *base)
{
	char	*ret;
	size_t	len;
	size_t	size;
	size_t	base_len;

	base_len = ft_strlen(base);
	len = ft_numlen(n, base_len);
	size = len + 1;
	if (n < 0)
		size += 1;
	ret = (char *)ft_calloc(size, sizeof(char));
	if (!ret)
		return (NULL);
	ft_ntoa(ret, n, base, len);
	return (ret);
}
