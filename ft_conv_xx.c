/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:26:12 by matt              #+#    #+#             */
/*   Updated: 2021/12/19 11:55:35 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (ft_return_checks(args, d) != 2)
		return (ft_return_checks_bis(args, d, res));
	ft_conv_x_negative(args, d);
	args->len += args->padding;
	if (ft_zero_and_minus_bis(args, res, d) != 2)
		return (ft_zero_and_minus(args, res, d));
	ft_print_space(args);
	args->res += ft_put_x_zero(res, args);
	return (ft_free_and_return(args, res));
}
