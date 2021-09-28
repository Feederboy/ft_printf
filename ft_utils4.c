/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:56:26 by matt              #+#    #+#             */
/*   Updated: 2021/09/28 15:32:23 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	getnb2(char **result, char *base, uint64_t n, int pos)
{
	if (n < (uint64_t)ft_strlen(base))
		(*result)[pos] = base[n % ft_strlen(base)];
	else
	{
		getnb(result, base, n / ft_strlen(base), pos - 1);
		(*result)[pos] = base[n % ft_strlen(base)];
	}
}

int	get_nb_size2(int base, uint64_t n)
{
	int	size;

	if (n < 0)
	{
		n = -n;
		size = 2;
	}
	else
		size = 1;
	while (n / base > 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

char			*ft_ultoa_base(uint64_t n, char *base)
{
	char		*result;
	int			size;
	uint64_t	nb;
	int			baselen;

	baselen = ft_strlen(base);
	nb = n;
	size = get_nb_size2(baselen, nb);
	result = malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[size] = '\0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	getnb2(&result, base, nb, size - 1);
	return (result);
}
