/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:10:35 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/26 01:56:48 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include "do_printf.h"
# include <stdbool.h>
# include <wchar.h>

bool	convert(const char **fmt, t_pinfo *info);
bool	convert_char(t_pinfo *info, wint_t c);
bool	convert_float(t_pinfo *info);
bool	convert_int(t_pinfo *info);
bool	convert_n(t_pinfo *info);
bool	convert_percent(t_pinfo *info);
bool	convert_ptr(t_pinfo *info);
bool	convert_str(t_pinfo *info);
bool	convert_uint(t_pinfo *info, char *base, char *prefix);

#endif
