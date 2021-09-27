/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:05:52 by matt              #+#    #+#             */
/*   Updated: 2021/09/27 15:48:25 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*read_args(t_args *args, char *itr, va_list ap)
{
	if (!itr || *itr != '%')
		return (itr);
	itr++;
	while (*itr)
	{
		init_args(args);
		itr = read_minus_zero_minus(args, itr);
		itr = read_starwidth_width(args, itr, ap);
		itr = read_prec_starprec_prec(args, itr, ap);
		if (ft_strchr("cspdiuxX%", *itr))
		{
			args->c = *itr;
			itr++;
			return (itr);
		}
		itr++;
	}
	return (itr);
}

int	ft_put_conv(t_args *args, va_list ap)
{
	if (args->c == 'c')
		return (ft_put_c(args, ap));
	else if (args->c == 's')
		return (ft_put_s(args, ap));
	else if (args->c == 'd')
		return (ft_put_d(args,ap));
	else if (args->c == 'p')
		return (ft_put_p(args, ap));
	else if (args->c == 'i')
		return (ft_put_i(args, ap));
	else if (args->c == 'u')
		return (ft_put_u(args, ap));
	else if (args->c == 'x')
		return (ft_put_x(args, ap));
	else if (args->c == 'X')
		return (ft_put_X(args, ap));
	else if (args->c == '%')
		return (ft_put_pct(args, ap));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	char	*itr;
	t_args	args;
	va_list	ap;
	int		res;

	itr = (char *)format;
	if (!itr)
		return (0);
	res = 0;
	va_start(ap, format);
	while (*itr)
	{
		if (*itr == '%')
		{
			itr = read_args(&args, itr, ap);
			res += ft_put_conv(&args, ap);
			continue ;
		}
		res += ft_putchar(*itr);
		itr++;
	}
	va_end(ap);
	return (res);
}
