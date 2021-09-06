/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:08:04 by matt              #+#    #+#             */
/*   Updated: 2021/09/06 18:55:59 by maquentr         ###   ########.fr       */
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
int		ft_put_d_zero(int d, t_args *args);
int		ft_put_u_zero(unsigned int d, t_args *args);



//Checkings
int	ft_check_full_zero(t_args *args, int d);
int	ft_check_full_zero_long(t_args *args, long d);
int	ft_check_prec_null_int(t_args *args, int d);
int	ft_check_prec_null_long(t_args *args, long d);

//SET
void	ft_set_args_for_specific_tests(t_args *args, int d);
int		ft_conv_check_args_putchar_return_res(t_args *args, int d);
void	ft_conv_d_negative(t_args *args, int d);
int		ft_conv_du_ifzero_ifelse(t_args *args, int d);
int		ft_conv_du_ifminus(t_args *args, int d);

//ARGS
void	init_args(t_args *args);
char	*read_minus_zero_minus(t_args *args, char *itr);
char	*read_starwidth_width(t_args *args, char *itr, va_list ap);
char	*read_prec_starprec_prec(t_args *args, char *itr, va_list ap);
void	ft_init_width_prec_starwid_starprec(t_args *args);
#endif
