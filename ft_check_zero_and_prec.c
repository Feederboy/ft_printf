/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_zero_and_prec.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:05:50 by maquentr          #+#    #+#             */
/*   Updated: 2021/11/29 15:32:57 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_full_zero(t_args *args, int d){
	if ((args->width == -1 && args->prec == 0 && d == 0)
		|| (!args->star_width && !args->star_prec && d == 0)
		|| (args->star_prec == 0 && d == 0))
		return (1);
	return (0);
}

int	ft_check_full_zero_bis(t_args *args, int d, char *res){
	if ((args->width == -1 && args->prec == 0 && d == 0)
		|| (!args->star_width && !args->star_prec && d == 0)
		|| (args->star_prec == 0 && d == 0))
	{
		free(res);
		return (1);
	}
	return (0);
}
int	ft_check_full_zero_bis_bis(t_args *args, int d, char **res){
	if ((args->width == -1 && args->prec == 0 && d == 0)
		|| (!args->star_width && !args->star_prec && d == 0)
		|| (args->star_prec == 0 && d == 0))
	{
		free(res);
		return (1);
	}
	return (0);
}
int	ft_check_full_zero_long(t_args *args, long d)
{
	if ((args->width == -1 && args->prec == 0 && d == 0)
		|| (!args->star_width && !args->star_prec && d == 0))
		return (1);
	return (0);
}

int	ft_check_prec_null_int(t_args *args, int d)
{
	if (!args->has_width && !args->has_star_width
		&& args->has_prec == 1 && args->prec == -1 && d == 0)
		return (1);
	return (0);
}
