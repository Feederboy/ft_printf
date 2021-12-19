/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:13:00 by matt              #+#    #+#             */
/*   Updated: 2021/12/19 12:17:52 by maquentr         ###   ########.fr       */
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

int	ft_conv_d_ifzero_ifelse(t_args *args, int d)
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
		ft_conv_d_ifzero_else(args, d);
		args->res += ft_put_d_zero(d, args);
		return (1);
	}
}

int	ft_conv_d_ifminus(t_args *args, int d)
{
	args->res += ft_put_d_zero(d, args);
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	return (args->res);
}

int	ft_put_d_zero(int d, t_args *args)
{
	int	res;

	res = 0;
	if (d == -2147483648)
	{
		res += ft_putchar('-');
		while (args->padding-- > 0)
			res += ft_putchar('0');
		res += ft_putstr("2147483648");
		return (res);
	}
	if (d < 0)
	{
		res += ft_putchar('-');
		d *= -1;
	}
	while (args->padding-- > 0)
		res += ft_putchar('0');
	if (d / 10)
		res += ft_put_d_zero(d / 10, args);
	if (args->prec_null == 0)
		res += ft_putchar((d % 10) + '0');
	else
		res += ft_putchar(' ');
	return (res);
}

int	ft_put_d(t_args *args, va_list ap)
{
	int	d;

	ft_init_width_prec_starwid_starprec(args);
	d = va_arg(ap, int);
	ft_set_args_for_specific_tests(args, d);
	if (ft_conv_check_args_putchar_return_res(args, d))
		return (args->res);
	if (ft_check_full_zero(args, d))
		return (0);
	if (ft_check_prec_null_int(args, d))
		return (0);
	args->len = ft_nb_digits(d);
	ft_conv_d_negative(args, d);
	args->len += args->padding;
	if (args->zero)
		if (ft_conv_d_ifzero_ifelse(args, d))
			return (args->res);
	if (args->minus)
		return (ft_conv_d_ifminus(args, d));
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	return (args->res + ft_put_d_zero(d, args));
}
