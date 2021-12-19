/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:45:34 by matt              #+#    #+#             */
/*   Updated: 2021/12/19 11:56:56 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_i_zero(int d, t_args *args)
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
		res += ft_put_i_zero(d / 10, args);
	if (args->prec_null == 0)
		res += ft_putchar((d % 10) + '0');
	else
		res += ft_putchar(' ');
	return (res);
}

int	ft_put_i(t_args *args, va_list ap)
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
	{
		if (ft_conv_d_ifzero_ifelse(args, d))
			return (args->res);
	}
	if (args->minus)
		return (ft_conv_d_ifminus(args, d));
	ft_print_space(args);
	return (args->res + ft_put_i_zero(d, args));
}
