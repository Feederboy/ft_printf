/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_X_set_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:57:47 by matt              #+#    #+#             */
/*   Updated: 2021/09/27 17:46:55 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_setprec_with_X_null(t_args *args)
{
	if (args->has_width && args->has_prec
		&& (args->prec == -1 || args->prec == 0))
		args->prec_null = 1;
}

void	ft_init_set_all_args(t_args *args, long d)
{
	if (args->has_width == -1 && d == 0)
		args->res += ft_putchar('0');
	if (args->has_width && args->width == 1 && d != 0)
	{
		args->has_width = 0;
		args->wid = -1;
	}
}

int	ft_set_all_args(t_args *args, long d)
{
	if (!args->has_star_width && args->has_star_prec
		&& args->star_prec < 0 && d == 0)
	{
		args->res += ft_putchar('0');
		return (1);
	}
	if (args->has_prec && args->prec == -1 && d == 0
		&& args->has_star_width && args->star_width > -1)
	{
		while (args->wid-- > 0)
			args->res += ft_putchar(' ');
		return (1);
	}
	if ((args->width > 0 || args->star_width > 0)
		&& (args->has_prec || args->has_star_prec)
		&& (args->prec == 0 || args->star_prec == 0) && d == 0)
	{
		while (args->wid-- > 0)
			args->res += ft_putchar(' ');
		return (1);
	}
	if (args->wid < 0)
	{
		args->wid *= -1;
		args->minus = 1;
	}
	return (0);
}
