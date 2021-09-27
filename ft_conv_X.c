/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:41:04 by matt              #+#    #+#             */
/*   Updated: 2021/09/27 15:25:59 by matt             ###   ########.fr       */
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

int		ft_conv_X_ifzero_ifelse(t_args *args, char *tmp, long s)
{
		if (args->has_prec || args->has_star_prec)
		{
			while ((args->wid - args->len) > 0)
			{
				args->res += ft_putchar(' ');
				args->wid--;
			}
			args->res += ft_put_X_zero(tmp, args);
			return (1);
		}
		else
		{
			if (s < 0)
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
			args->res += ft_put_X_zero(tmp, args);
			return (1);
		}
}

int		ft_conv_X_ifminus(t_args *args, char *tmp)
{
	args->res += ft_put_X_zero(tmp, args);
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	return (args->res);
}

int		ft_put_X_zero(char *str, t_args *args)
{
	int res;

	res = 0;
	while (args->padding-- > 0)
		res += ft_putchar('0');
	if (args->prec_null == 0)
		res += ft_putstr(str);
	else
		res += ft_putchar(' ');
	return (res);
}

int		ft_put_X(t_args *args, va_list ap)
{
	long d;
	char *tmp;
	char *base;


	base = "0123456789ABCDEF";
	ft_init_width_prec_starwid_starprec(args);
	d = (long)va_arg(ap, unsigned int);
	if (ft_set_all_args(args, d))
		return (args->res);
	tmp = ft_itoa_base(d, base);
	args->len = ft_strlen(tmp);
	if (ft_check_full_zero(args, d))
		return (0);
	if (ft_check_prec_null_long(args, d))
		return (0);
	ft_conv_X_negative(args, d);
	args->len += args->padding;
	if (args->zero)
	{
		if (ft_conv_X_ifzero_ifelse(args, tmp, d))
			return (args->res);
	}
	if (args->minus)
	{
		return (ft_conv_X_ifminus(args, tmp));
	}
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	return (args->res + ft_put_X_zero(tmp, args));
}
