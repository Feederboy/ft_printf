/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_zero_and_prec_bis.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:31:58 by matt              #+#    #+#             */
/*   Updated: 2021/11/29 15:33:01 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_check_prec_null_long(t_args *args, long d)
{
	if (!args->has_width && args->has_prec == 1 && args->prec == -1 && d == 0)
		return (1);
	return (0);
}
