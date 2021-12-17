/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_X_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:45:15 by matt              #+#    #+#             */
/*   Updated: 2021/11/29 15:46:15 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_X_negative(t_args *args, long s)
{
	if (s < 0)
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

int	ft_conv_X_ifzero_ifelse(t_args *args, char *tmp, long s)
{
	if (args->has_prec || args->has_star_prec)
		return (ft_conv_X_has_prec(args, tmp, s));
	else
		return (ft_conv_X_else_prec(args, tmp, s));
}

int	ft_conv_X_ifzero_ifelse_bis(t_args *args, char *tmp, long s)
{
	(void)tmp;
	(void)s;

	if (args->has_prec || args->has_star_prec)
		return (0);
	else
		return (1);
	return (2);
}

int	ft_conv_X_ifminus(t_args *args, char *tmp, long d)
{
	if (d == 0 && args->has_prec && args->prec == -1 && args->wid != -1)
	{
		while ((args->wid + 1 - args->len) > 0)
		{
			args->res += ft_putchar(' ');
			args->wid--;
		}
		return (args->res);
	}
	if (d == 0 && args->wid == 0 && args->precision == -1)
		return (args->res += ft_putchar('0'));
	if (d == 0 && args->prec == -1 && args->has_prec)
		args->wid += 1;
	args->res += ft_put_X_zero(tmp, args);
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	return (args->res);
}

int	ft_put_X_zero(char *str, t_args *args)
{
	int	res;

	res = 0;
	while (args->padding-- > 0)
		res += ft_putchar('0');
	if (args->prec_null == 0)
		res += ft_putstr(str);
	else
		res += ft_putchar(' ');
	return (res);
}
