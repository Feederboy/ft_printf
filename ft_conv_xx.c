/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:26:12 by matt              #+#    #+#             */
/*   Updated: 2021/09/27 15:36:16 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_x(t_args *args, va_list ap)
{
	long	d;
	char	*tmp;
	char	*base;

	base = "0123456789abcdef";
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
		if (ft_conv_X_ifzero_ifelse(args, tmp, d))
			return (args->res);
	if (args->minus)
		return (ft_conv_X_ifminus(args, tmp));
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	return (args->res + ft_put_X_zero(tmp, args));
}
