/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:15:33 by maquentr          #+#    #+#             */
/*   Updated: 2021/12/19 13:45:50 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_full_zero_long_return(t_args *args, uint64_t s, char *res)
{
	if (ft_check_full_zero_long(args, s))
	{
		free(res);
		return (0);
	}
	return (1);
}

char	*ft_set_res_ultoa_prefix(t_args *args, char *res, uint64_t s)
{
	if (s == 0 && args->has_prec)
	{
		free(res);
		res = "0x";
	}
	return (res);
}

int	ft_pminusbis(t_args *args)
{
	if (args->minus)
	{
		return (1);
	}
	return (-2);
}

int	ft_pminus(t_args *args, char *res)
{
	if (args->minus)
	{
		free(res);
		return (ft_conv_p_ifminus(args, res));
	}
	return (-2);
}
