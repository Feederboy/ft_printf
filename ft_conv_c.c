/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:32:25 by matt              #+#    #+#             */
/*   Updated: 2021/09/27 15:33:04 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_c(t_args *args, va_list ap)
{
	int c;

	c = va_arg(ap, int);
	ft_init_width_prec_starwid_starprec(args);
	if (args->minus)
	{
		args->res += ft_putchar(c + 0);
		while (args->wid > 1)
		{
			args->res += ft_putchar(' ');
			args->wid--;
		}
		return (args->res);
	}
	else
	{
		while (args->wid > 1)
		{
			args->res += ft_putchar(' ');
			args->wid--;
		}
	}
	return (args->res + ft_putchar(c + 0));
}
