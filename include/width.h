/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:05:23 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/15 17:33:54 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDTH_H
# define WIDTH_H

# include <stdarg.h>

unsigned int	get_width(const char **fmt, va_list va, unsigned int *flags);

#endif
