/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_X_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:25:53 by matt              #+#    #+#             */
/*   Updated: 2021/10/12 13:15:40 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_space(t_args *args)
{
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
}

int	ft_free_and_return(t_args *args, char *res)
{
	free(res);
	return (args->res);
}

int	ft_free_and_return_bis(t_args *args, char **res)
{
	free(res);
	return (args->res);
}
int	ft_conv_X_has_prec(t_args *args, char *tmp, long s)
{
	if (args->wid != 0 && args->has_prec && args->prec == -1 && s == 0)
	{
		while ((args->wid + 1 - args->len) > 0)
		{
			args->res += ft_putchar(' ');
			args->wid --;
		}
		return (1);
	}
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
	args->res += ft_put_X_zero(tmp, args);
	return (1);
}

int	ft_conv_X_else_prec(t_args *args, char *tmp, long s)
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
	args->res += ft_put_X_zero(tmp, args);
	return (1);
}
