/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:26:49 by maquentr          #+#    #+#             */
/*   Updated: 2021/12/19 12:11:35 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_u_ifelse_bis(unsigned int d, t_args *args)
{
	if (d < 0)
	{
		if ((args->len - 1) < args->wid)
			args->padding = (args->wid - args->len);
		else
			args->padding = 0;
	}
	else
	{
		if (args->len < args->wid)
			args->padding = (args->wid - args->len);
		else
			args->padding = 0;
	}
}
