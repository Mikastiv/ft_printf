/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:25:26 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/16 23:20:22 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	add_padding(t_pinfo *info, int *len, char c)
{
	while ((*len)++ < info->width)
	{
		info->ft_putc(c);
		info->count++;
	}
}
