/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:34:52 by maquentr          #+#    #+#             */
/*   Updated: 2021/12/19 11:36:39 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*read_digit(t_args *args, char *itr)
{
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
