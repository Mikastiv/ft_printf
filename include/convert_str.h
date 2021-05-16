/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:44:26 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/16 16:48:18 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_STR_H
# define CONVERT_STR_H

# include "do_printf.h"

void	convert_str(const char **fmt, t_pinfo *info, void (*ft_putc)(char));

#endif
