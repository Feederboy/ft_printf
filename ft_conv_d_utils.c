/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:45:21 by maquentr          #+#    #+#             */
/*   Updated: 2021/12/19 11:39:20 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_d_ifzero_else(t_args *args, int d)
{
	if (d < 0)
	{
		if ((args->len -1) < args->wid)
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
