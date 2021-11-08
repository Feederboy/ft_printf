/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:41:04 by matt              #+#    #+#             */
/*   Updated: 2021/11/08 17:32:02 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_return_checks(t_args *args, long d)
{
	if (ft_check_full_zero(args, d))
		return (0);
	if (ft_check_prec_null_long(args, d))
		return (1);
	return (2);
}
int ft_return_checks_bis(t_args *args, long d, char *res)
{
	if (ft_check_full_zero(args, d))
	{
		free(res);
		return (0);
	}
	if (ft_check_prec_null_long(args, d))
		return (ft_free_and_return(args, res));
	return (2);
}

int	ft_zero_and_minus_bis(t_args *args, char *res, long d)
{
	if (args->zero)
		if ((ft_conv_X_ifzero_ifelse_bis(args, res, d)) != 2)
			return (0);
	if (args->minus)
		return (1);
	return (2);
}

int	ft_zero_and_minus(t_args *args, char *res, long d)
{
	if (args->zero)
		if (ft_conv_X_ifzero_ifelse(args, res, d))
		{
//			printf("5\n");
			return (ft_free_and_return(args, res));
		}
	if (args->minus)
	{
//		printf("6\n");
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
//	printf("1\n");
	d = (long)va_arg(ap, unsigned int);
	if (ft_set_all_args(args, d))
		return (args->res);
//	printf("2\n");
	res = ft_itoa_base(d, base);
	if (!res)
		return (-1);
	args->len = ft_strlen(res);
	if (ft_return_checks(args, d) != 2)
		return (ft_return_checks_bis(args, d, res));
//	printf("3\n");
	ft_conv_X_negative(args, d);
//	printf("4\n");
	args->len += args->padding;
	if (ft_zero_and_minus_bis(args, res, d) != 2)
		return (ft_zero_and_minus(args, res, d));
	ft_print_space(args);
	args->res += ft_put_X_zero(res, args);
	return (ft_free_and_return(args, res));
}
