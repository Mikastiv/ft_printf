/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:10:20 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/22 18:10:12 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "convert_char.h"
#include "convert_str.h"
#include "convert_ptr.h"
#include "convert_percent.h"
#include "convert_int.h"
#include "convert_uint.h"

bool	convert(const char **fmt, t_pinfo *info)
{
	bool	success;

	success = true;
	if (**fmt == 'c' && (*fmt)++)
		success = convert_char(info, (char)va_arg(info->va, int));
	else if (**fmt == 's' && (*fmt)++)
		success = convert_str(info);
	else if (**fmt == 'p' && (*fmt)++)
		success = convert_ptr(info);
	else if (**fmt == '%' && (*fmt)++)
		success = convert_percent(info);
	else if ((**fmt == 'd' || **fmt == 'i') && (*fmt)++)
		success = convert_int(info);
	else if (**fmt == 'u' && (*fmt)++)
		success = convert_uint(info, "0123456789");
	else if (**fmt == 'x' && (*fmt)++)
		success = convert_uint(info, "0123456789abcdef");
	else if (**fmt == 'X' && (*fmt)++)
		success = convert_uint(info, "0123456789ABCDEF");
	else
		success = convert_char(info, *((*fmt)++));
	return (success);
}
