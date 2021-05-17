/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:25:26 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/16 20:31:10 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	add_padding(t_pinfo *info, int *len)
{
	while ((*len)++ < info->width)
	{
		info->ft_putc(' ');
		info->count++;
	}
}
