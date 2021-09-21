/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:24:36 by matt              #+#    #+#             */
/*   Updated: 2021/09/21 16:37:48 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_u_ifzero_ifelse(t_args *args, unsigned int d)
{
		if (args->has_prec || args->has_star_prec)
		{
			while ((args->wid - args->len) > 0)
			{
				args->res += ft_putchar(' ');
				args->wid--;
			}
			args->res += ft_put_u_zero(d, args);
			return (1);
		}
		else
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
			args->res += ft_put_u_zero(d, args);
			return (1);
		}
}

int		ft_conv_u_ifminus(t_args *args, unsigned int d)
{

	args->res += ft_put_u_zero(d, args);
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	return (args->res);
}
