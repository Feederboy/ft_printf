/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_pct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:37:25 by matt              #+#    #+#             */
/*   Updated: 2021/09/27 15:39:50 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_pct_ifminus(t_args *args)
{
	args->res = ft_putchar('%');
	while (args->wid > 1)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
}

void	ft_conv_pct_ifzero(t_args *args)
{
	while (args->wid > 1)
	{
		args->res += ft_putchar('0');
		args->wid--;
	}
}

void	ft_conv_pct_elsezero(t_args *args)
{
	while (args->wid > 1)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
}

int		ft_put_pct(t_args *args, va_list ap)
{
	(void)ap;

	if (args->has_width)
		args->wid = args->width;
	else
		args->wid = 0;
	if (args->minus == 1)
	{
		ft_conv_pct_ifminus(args);
		return (args->res);
	}
	else
	{
		if (args->zero)
			ft_conv_pct_ifzero(args);
		else
			ft_conv_pct_elsezero(args);
	}
	return (args->res + ft_putchar('%'));
}
