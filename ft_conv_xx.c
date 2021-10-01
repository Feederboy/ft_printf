/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:26:12 by matt              #+#    #+#             */
/*   Updated: 2021/10/01 15:18:33 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



/*
int	ft_put_x(t_args *args, va_list ap)
{
	long	d;
	char	*base;
	char	*res;

	base = "0123456789abcdef";
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
		return (0);
	ft_conv_X_negative(args, d);
	args->len += args->padding;
	if (args->zero)
	{
		if (ft_conv_X_ifzero_ifelse(args, res, d))
		{
			free(res);
			return (args->res);
		}
	}
	if (args->minus)
	{
		args->res = ft_conv_X_ifminus(args, res);
		free(res);
		return (args->res);
	}
	//	return (ft_conv_X_ifminus(args, res));
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	args->res += ft_put_X_zero(res, args);
	free(res);
	return (args->res);
}
*/





int	ft_put_x(t_args *args, va_list ap)
{
	long	d;
	char	*base;
	char	*res;

	base = "0123456789abcdef";
	ft_init_width_prec_starwid_starprec(args);
	d = (long)va_arg(ap, unsigned int);
	if (ft_set_all_args(args, d))
		return (args->res);
	res = ft_itoa_base(d, base);
//	printf("RES = %s\n", res);
	if (!res)
		return (-1);
//	printf("RES2 = %s\n", res);
	args->len = ft_strlen(res);
	if (ft_check_full_zero_bis(args, d, res))
		return (0);
//	printf("RES3 = %s\n", res);
	if (ft_check_prec_null_long(args, d))
	{
		free(res);
		return (args->res);
	}
//	printf("RES4 = %s\n", res);
	ft_conv_X_negative(args, d);
	args->len += args->padding;
	if (args->zero)
	{
		if (ft_conv_X_ifzero_ifelse(args, res, d))
		{
			free(res);
			return (args->res);
		}
	}
	if (args->minus)
	{
		args->res = ft_conv_X_ifminus(args, res, d);
		free(res);
		return (args->res);
	}
	//	return (ft_conv_X_ifminus(args, res));
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	args->res += ft_put_X_zero(res, args);
	free(res);
	return (args->res);
}
