/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:24:36 by matt              #+#    #+#             */
/*   Updated: 2021/09/27 15:42:07 by matt             ###   ########.fr       */
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

int		ft_put_u_zero(unsigned int d, t_args *args)
{
	int res;

	res =0;
	if (d == 4294967295)
	{
		while (args->padding-- > 0)
			res += ft_putchar('0');
		res += ft_putstr("4294967295");
		return (res);
	}
	while (args->padding-- > 0)
		res += ft_putchar('0');
	if (d / 10)
		res += ft_put_u_zero(d / 10, args);
	if (args->prec_null == 0)
		res += ft_putchar((d % 10) + '0');
	else
		res += ft_putchar(' ');
	return (res);
}

int		ft_put_u(t_args *args, va_list ap)
{
	unsigned int d;

	ft_init_width_prec_starwid_starprec(args);
	d = va_arg(ap, unsigned int);
	ft_set_args_for_specific_tests(args, d);
	if (ft_conv_check_args_putchar_return_res(args, d))
		return (args->res);
	if (args->has_width == -1 && d == 0)
		args->res += ft_putchar('0');
	if (ft_check_full_zero(args, d))
		return (0);
	if (ft_check_prec_null_int(args, d))
		return (0);
	args->len = ft_nb_digits_unsigned(d);
	if (args->len < args->precision)
		args->padding = (args->precision - args->len);
	else
		args->padding = 0;
	args->len += args->padding;
	if (args->zero)
	{
		if (ft_conv_u_ifzero_ifelse(args, d))
			return (args->res);
	}
	if (args->minus)
		return (ft_conv_u_ifminus(args, d));
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	return (args->res + ft_put_u_zero(d, args));
}
