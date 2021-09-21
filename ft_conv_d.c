/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:13:00 by matt              #+#    #+#             */
/*   Updated: 2021/09/21 16:13:53 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_d_negative(t_args *args, int d)
{
	if (d < 0)
	{
		if ((args->len - 1) < args->precision)
			args->padding = (args->precision - (args->len - 1));
		else
			args->padding = 0;
	}
	else
	{
		if (args->len < args->precision)
			args->padding = (args->precision - args->len);
		else
			args->padding = 0;
	}
}


int		ft_conv_d_ifzero_ifelse(t_args *args, int d)
{
		if (args->has_prec || args->has_star_prec)
		{
			while ((args->wid - args->len) > 0)
			{
				args->res += ft_putchar(' ');
				args->wid--;
			}
			args->res += ft_put_d_zero(d, args);
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
			args->res += ft_put_d_zero(d, args);
			return (1);
		}
}

int		ft_conv_d_ifminus(t_args *args, int d)
{

	args->res += ft_put_d_zero(d, args);
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	return (args->res);
}
