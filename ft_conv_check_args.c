/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_check_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:58:15 by maquentr          #+#    #+#             */
/*   Updated: 2021/09/27 14:04:58 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_args_for_specific_tests(t_args *args, int d)
{
	if (args->has_width && args->has_prec && d == 0
		&& (args->prec == -1 || args->prec == 0))
		args->prec_null = 1;
	if (args->has_width == -1 && d == 0)
		args->res += ft_putchar('0');
	if (args->has_width && args->width == 1 && d != 0)
	{
		args->has_width = 0;
		args->width = -1;
	}
}

int	ft_conv_check_args_putchar_return_res(t_args *args, int d)
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
	return (0);
}
