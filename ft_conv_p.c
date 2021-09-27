/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:22:34 by matt              #+#    #+#             */
/*   Updated: 2021/09/27 23:28:02 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_p_negative(t_args *args, long long s)
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

int	ft_conv_p_ifzero_ifelse(t_args *args, char *tmp, long long s)
{
	if (args->has_prec || args->has_star_prec)
	{
		while ((args->wid - args->len) > 0)
		{
			args->res += ft_putchar(' ');
			args->wid--;
		}
		args->res += ft_put_p_zero(tmp, args);
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
		args->res += ft_put_p_zero(tmp, args);
		return (1);
	}
}

int	ft_conv_p_ifminus(t_args *args, char *tmp)
{
	args->res += ft_put_p_zero(tmp, args);
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	return (args->res);
}

int	ft_put_p_zero(char *str, t_args *args)
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

int	ft_put_p(t_args *args, va_list ap)
{
	unsigned long	s;
	char	*base;
	char	*tmp;
	char	*res;

	ft_init_width_prec_starwid_starprec(args);
	base = "0123456789abcdef";
	s = (unsigned long)va_arg(ap, void*);
	tmp = ft_ultoa_base(s, base);
	printf("HELLO = %s\n", tmp);
	if (!tmp)
		return (-1);
	res = ft_strjoin("0x", tmp);
	free(tmp);
	if (s == 0 && args->has_prec)
		res = "0x";
	args->len = ft_strlen(res);
	if (ft_check_full_zero_long(args, s))
		return (0);
	ft_conv_p_negative(args, s);
	args->len += args->padding;
	if (args->zero)
		if (ft_conv_p_ifzero_ifelse(args, res, s))
			return (args->res);
	if (args->minus)
		return (ft_conv_p_ifminus(args, res));
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	args->res += ft_put_p_zero(res, args);
	free(res);
	return (args->res);
}
