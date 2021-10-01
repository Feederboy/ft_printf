/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:01:48 by matt              #+#    #+#             */
/*   Updated: 2021/10/01 12:02:25 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_set_prefix(char *str)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin("0x", tmp);
	free(tmp);
	if (!str)
		return (NULL);
	return (str);
}

void	ft_print_width(t_args *args)
{
	while ((args->wid - args->len) > 0)
	{
		args->res += ft_putchar(' ');
		args->wid--;
	}
}
