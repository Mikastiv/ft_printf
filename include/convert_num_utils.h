/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:50:14 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/24 21:30:19 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_NUM_UTILS_H
# define CONVERT_NUM_UTILS_H

# include "do_printf.h"

void	add_num_padding(t_pinfo *info, char c);
void	add_num_padding_sign(t_pinfo *info, char c, char *prefix);
void	calculate_padding(t_pinfo *info, char *str);

#endif
