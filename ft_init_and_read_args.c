/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_and_read_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:24:37 by maquentr          #+#    #+#             */
/*   Updated: 2021/09/06 16:57:58 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_args(t_args *args)
{
	args->width = -1;
	args->has_width = 0;
	args->prec = -1;
	args->has_prec = 0;
	args->minus = 0;
	args->has_zero = 0;
	args->zero = 0;
	args->has_star_width = 0;
	args->star_width = -1;
	args->has_star_prec = 0;
	args->star_prec = -1;
	args->percent = 0;
	args->wid = 0;
	args->res = 0;
	args->precision = 0;
	args->padding = 0;
	args->len = 0;
	args->prec_null = 0;
}

char	*read_minus_zero_minus(t_args *args, char *itr)
{
	if (*itr == '-')
	{
		args->minus = 1;
		itr++;
	}
	if (*itr == '0')
	{
		args->zero = 1;
		if (args->minus == 1)
			args->zero = 0;
		itr++;
	}
	if (*itr == '-')
	{
		args->minus = 1;
		if (args->zero)
			args->zero = 0;
		itr++;
	}
	return (itr);
}

char	*read_starwidth_width(t_args *args, char *itr, va_list ap)
{
	if (*itr == '*')
	{
		args->has_star_width = 1;
		args->star_width = va_arg(ap, int);
		if (args->star_width < 0)
		{
			args->star_width *= -1;
			args->minus = 1;
			if (args->zero)
				args->zero = 0;
		}
		itr++;
	}
	if (ft_isdigit(*itr))
	{
		args->has_width = 1;
		args->width = ft_atoi(itr);
		itr += ft_nb_dig(itr);
	}
	return (itr);
}

char	*read_prec_starprec_prec(t_args *args, char *itr, va_list ap)
{
	if (*itr == '.')
	{
		args->has_prec = 1;
		itr++;
	}
	if (*itr == '*')
	{
		args->has_star_prec = 1;
		args->has_prec = 0;
		args->star_prec = va_arg(ap, int);
		if (args->star_prec < 0)
		{
			args->star_prec = -1;
			args->has_star_prec = 0;
		}
		itr++;
	}
	if (ft_isdigit(*itr))
	{
		if (args->has_star_prec == 0)
		{
			args->prec = ft_atoi(itr);
			itr += ft_nb_dig(itr);
		}
		else
			itr += ft_nb_digits(ft_atoi(itr));
	}
	return (itr);
}

void	ft_init_width_prec_starwid_starprec(t_args *args)
{
	if (args->has_width)
		args->wid = args->width;
	if (args->has_prec)
		args->precision = args->prec;
	if (args->has_star_width)
		args->wid = args->star_width;
	if (args->has_star_prec)
		args->precision = args->star_prec;
}
