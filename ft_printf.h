/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:08:04 by matt              #+#    #+#             */
/*   Updated: 2021/08/17 00:09:49 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_args
{
	int c;
	int width;
	int has_width;
	int prec;
	int has_prec;
	int minus;
	int has_zero;
	int zero;
	int has_star_width;
	int star_width;
	int has_star_prec;
	int star_prec;
	int percent;
	int wid;
	int precision;
	int padding;
	int len;
	int prec_null;
	int res;
	int a;
}				t_args;


//UTILS
char	*ft_itoa_base(long n, char *base);
int	ft_strlen(char *s);
char	*ft_strchr(char *str, char c);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putstrl(char *str, int len);
int	ft_isdigit(char c);
int	ft_atoi(const char *str);
int	ft_nb_digits(int d);
int	ft_nb_digits_unsigned(unsigned int d);
int	get_nb_size(int base, long long n);
char	*ft_strjoin(char *s1, char *s2);
void	getnb(char **result, char *base, long long n, int pos);
char	*ft_itoa_base(long n, char *base);
int		ft_nb_dig(char *str);
int		ft_printf(const char *format, ...);

//PARSING ARGS
//void	init_args(t_args *args);
//int	set_minus_zero_minus(t_args *args, char **itr);
//int	set_starwidh_width(t_args *args, char **itr, va_list ap);
//int	set_if_digit(t_args *args, char **itr);
//int	set_prec_starprec_prec(t_args *args, char **itr, va_list ap);

#endif
