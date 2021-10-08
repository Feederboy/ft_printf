/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:41:04 by matt              #+#    #+#             */
/*   Updated: 2021/10/08 16:07:07 by matt             ###   ########.fr       */
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
	if (d == 0 && args->wid == 0 && args->prec == -1)
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

int ft_return_checks(t_args *args, long d, char **res)
{
	if (ft_check_full_zero_bis(args, d, *res))
		return (0);
	if (ft_check_prec_null_long(args, d))
		return (ft_free_and_return(args, *res));
	return (2);
}

int	ft_zero_and_minus(t_args *args, char *res, long d)
{
	if (args->zero)
		if (ft_conv_X_ifzero_ifelse(args, res, d))
			return (ft_free_and_return(args, res));
	if (args->minus)
	{
		args->res = ft_conv_X_ifminus(args, res, d);
		return (ft_free_and_return(args, res));
	}
	return (2);
}


int	ft_put_X(t_args *args, va_list ap)
{
	long	d;
	char	*base;
	char	*res;

	base = "0123456789ABCDEF";
	ft_init_width_prec_starwid_starprec(args);
	d = (long)va_arg(ap, unsigned int);
	if (ft_set_all_args(args, d))
		return (args->res);
	res = ft_itoa_base(d, base);
	if (!res)
		return (-1);
	args->len = ft_strlen(res);
	if (ft_check_full_zero_bis(args, d, res))
		return (0);
	if (ft_check_prec_null_long(args, d))
		return (ft_free_and_return(args, res));
	ft_conv_X_negative(args, d);
	args->len += args->padding;
	if (args->zero)
		if (ft_conv_X_ifzero_ifelse(args, res, d))
			return (ft_free_and_return(args, res));
	if (args->minus)
	{
		args->res = ft_conv_X_ifminus(args, res, d);
		return (ft_free_and_return(args, res));
	}
	ft_print_space(args);
	args->res += ft_put_X_zero(res, args);
	return (ft_free_and_return(args, res));
}
