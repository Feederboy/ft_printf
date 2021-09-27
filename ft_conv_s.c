/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:49:13 by matt              #+#    #+#             */
/*   Updated: 2021/09/27 15:31:22 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_set_args_s(t_args *args , char *s)
{
	if (!args->has_width && !args->has_star_width && args->star_prec == 0)
		return (0);
	args->len = ft_strlen(s);
	if (args->has_prec && args->has_star_prec && args->star_prec < 0)
		return (args->res + ft_putstr(s));
	if (args->has_prec || args->has_star_prec)
	{
		if (args->precision == -1)
			args->len = 0;
		else if (args->len > args->precision)
			args->len = args->precision;
	}
	return (1);
}

void	ft_if_minus(t_args *args, char *s)
{
	args->res += ft_putstrl(s,args->len);
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
}

int	ft_else_minus(t_args *args, char *s)
{
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	if (args->has_prec || args->has_star_prec)
	{
		while (*s && args->precision-- > 0)
		{
			args->res += ft_putchar(*s);
			s++;
		}
		return (1);
	}
	return (0);
}

int	ft_put_s(t_args *args, va_list ap)
{
	char	*s;

	ft_init_width_prec_starwid_starprec(args);
	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	if (!args->has_width && !args->has_star_width && args->star_prec == 0)
		return (0);
	args->len = ft_strlen(s);
	if (args->has_prec && args->has_star_prec && args->star_prec < 0)
		return (args->res + ft_putstr(s));
	if (args->has_prec || args->has_star_prec)
	{
		if (args->precision == -1)
			args->len = 0;
		else if (args->len > args->precision)
			args->len = args->precision;
	}
	if (args->minus)
	{
		ft_if_minus(args, s);
		return (args->res);
	}
	else
		if (ft_else_minus(args, s))
			return (args->res);
	return (args->res + ft_putstrl(s, args->len));
}
