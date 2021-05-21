/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:10:20 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/21 19:35:12 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "convert_char.h"
#include "convert_str.h"
#include "convert_ptr.h"
#include "convert_percent.h"
#include "convert_int.h"
#include "convert_uint.h"

void	convert(const char **fmt, t_pinfo *info)
{
	if (**fmt == 'c')
		convert_char(fmt, info);
	else if (**fmt == 's')
		convert_str(fmt, info);
	else if (**fmt == 'p')
		convert_ptr(fmt, info);
	else if (**fmt == '%')
		convert_percent(fmt, info);
	else if (**fmt == 'd' || **fmt == 'i')
		convert_int(fmt, info, va_arg(info->va, int));
	else if (**fmt == 'u')
		convert_uint(fmt, info, va_arg(info->va, unsigned int));
}
