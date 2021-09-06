/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:05:52 by matt              #+#    #+#             */
/*   Updated: 2021/09/06 15:54:46 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_full_zero(t_args *args, int d)
{
	if ((args->width == -1 && args->prec == 0 && d == 0) || (!args->star_width &&	!args->star_prec && d == 0)
			|| (args->star_prec == 0 && d == 0))
		return (1);
	return (0);
}

int		ft_check_full_zero_long(t_args *args, long d)
{
	if ((args->width == -1 && args->prec == 0 && d == 0) || (!args->star_width &&	!args->star_prec && d == 0))
		return (1);
	return (0);
}

int		ft_check_prec_null_int(t_args *args, int d) //permet d'afficher %.i avec i = 0
{
	if (!args->has_width && !args->has_star_width && args->has_prec == 1 && args->prec == -1 && d == 0)
		return (1);
	return (0);
}

int		ft_check_prec_null_long(t_args *args, long d) //permet d'afficher %.i avec i = 0
{
	if (!args->has_width && args->has_prec == 1 && args->prec == -1 && d == 0)
		return (1);
	return (0);
}
void	aff_args(t_args *args)
{
	printf("width = %d\nhas_width = %d\nprec = %d\nhas_prec = %d\nminus = %d\nhas_zero = %d\nzero = %d\nhas_star_width = %d\nstar_width = %d\nhas_star_prec = %d\nstar_prec = %d\npercent = %d\nwid = %d\nprecision = %d\npadding = %d\nlen = %d\nprec_null = %d\na = %d\n\n\n\n",
			args->width,
			args->has_width,
			args->prec,
			args->has_prec,
			args->minus,
			args->has_zero,
			args->zero,
			args->has_star_width,
			args->star_width,
			args->has_star_prec,
			args->star_prec,
			args->percent,
			args->wid,
			args->precision,
			args->padding,
			args->len,
			args->prec_null,
			args->a);
}

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
	//minus
	if (*itr == '-')
	{
		args->minus = 1;
		itr++;
	}
	//zero
	if (*itr == '0')
	{
		args->zero = 1;
		if (args->minus == 1)
			args->zero = 0;
		itr++;
	}
	//minus
	if (*itr == '-')
	{
		args->minus = 1;
		if (args->zero)
			args->zero = 0;
		itr++;
	}
	return (itr);
}



	char	*read_args(t_args *args, char *itr, va_list ap)
	{

		if (!itr || *itr != '%')
			return (itr);
		itr++;
		while (*itr)
		{
			init_args(args);
			itr = read_minus_zero_minus(args, itr);
			// * width
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
			//widt ---- if there's no *width before
			if (ft_isdigit(*itr))
			{
				args->has_width = 1;
				args->width = ft_atoi(itr);
				itr += ft_nb_dig(itr);
			}
			//.
			if (*itr == '.')
			{
				args->has_prec = 1;
				itr++;
			}
			// * prec
			if (*itr == '*')
			{
				args->has_star_prec = 1;
				args->has_prec = 0;
				args->star_prec = va_arg(ap, int);
				if (args->star_prec < 0)
				{
					args->star_prec = -1;  //SI PREC NEGATIVE ALORS PAS COMPTEE
					args->has_star_prec = 0;
				}
				itr++;
			}
			//prec  --- if there's no *prec before
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
			//dxs
			if (ft_strchr("cspdiuxX%", *itr))
			{
				args->c = *itr;
				itr++;
				return (itr);
			}
			itr++;
		}
		return (itr);
	}

//WID EST REMIS A ZERO CAR IL RENTRE DANS LE ELSE DU CHECK STARWIDTH
void	ft_init_width_prec_starwid_starprec(t_args *args)
	{
		if (args->has_width)
		{
			args->wid = args->width;
		}
		if (args->has_prec)
			args->precision = args->prec;
		if (args->has_star_width)
			args->wid = args->star_width;
		if (args->has_star_prec)
			args->precision = args->star_prec;
	}



	//--------- PPPPPPP ---------------

	int		ft_put_p_zero(char *str, t_args *args)
	{
		int res;

		res = 0;
		while (args->padding-- > 0)
			res += ft_putchar('0');
		if (args->prec_null == 0)
			res += ft_putstr(str);
		else
			res += ft_putchar(' ');
		return (res);
	}

	int		ft_put_p(t_args *args, va_list ap)
	{

		long s;
		char *base;
		char *tmp;

		ft_init_width_prec_starwid_starprec(args);
		base = "0123456789abcdef";
		s = (long)va_arg(ap, void *);
		tmp = ft_itoa_base(s, base);
		tmp = ft_strjoin("0x", tmp);
		if (s == 0 && args->has_prec)
			tmp = "0x";
		args->len = ft_strlen(tmp);
		if (ft_check_full_zero_long(args, s))
			return (0);
		if (s < 0)
		{
			if ((args->len - 1) < args->precision)
				args->padding = (args->precision - (args->len - 1));
			else
				args->padding = 0;
		}
		else
		{
			if (args->len < args->precision)
				args->padding = (args->precision - args->len);
			else
				args->padding = 0;
		}
		args->len += args->padding;
		if (args->zero)
		{
			if (args->has_prec)
			{
				while ((args->wid - args->len) > 0)
				{
					args->res += ft_putchar(' ');
					args->wid--;
				}
				args->res += ft_put_p_zero(tmp, args);
				return (args->res);
			}
			else
			{
				if (s < 0)
				{
					if ((args->len - 1) < args->wid)
						args->padding = args->wid - args->len;
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
				args->res += ft_put_p_zero(tmp, args);
				return (args->res);
			}
		}
		if (args->minus)
		{
			args->res += ft_put_p_zero(tmp, args);
			while ((args->wid - args->len) > 0)
			{
				args->res += ft_putchar(' ');
				args->wid--;
			}
			return (args->res);
		}
		while ((args->wid - args->len) > 0)
		{
			args->res += ft_putchar(' ');
			args->wid--;
		}
		return (args->res + ft_put_p_zero(tmp, args));
	}



	// -----------  XXXXXXXX --------------

	int		ft_put_X_zero(char *str, t_args *args)
	{
		int res;

		res = 0;
		while (args->padding-- > 0)
			res += ft_putchar('0');
		if (args->prec_null == 0)
			res += ft_putstr(str);
		else
			res += ft_putchar(' ');
		return (res);
	}

	int		ft_put_X(t_args *args, va_list ap)
	{
		long d;
		char *tmp;
		char *base;


		base = "0123456789ABCDEF";
		if (args->has_width && args->has_prec && (args->prec == -1 || args->prec == 0))
			args->prec_null = 1; //pour %5.0i et 5.i   avec i = 0
		ft_init_width_prec_starwid_starprec(args);
		d = (long)va_arg(ap, unsigned int);
		if (args->has_width == -1 && d == 0)
			args->res += ft_putchar('0');
		if (args->has_width && args->width == 1 && d != 0)
		{
			args->has_width = 0;
			args->wid = -1;
		}
		if (!args->has_star_width && args->has_star_prec && args->star_prec < 0 && d == 0)
		{
			args->res += ft_putchar('0');
			return (args->res);
		}
		if (args->has_prec && args->prec == -1 && d == 0 && args->has_star_width && args->star_width > -1) // pour %*.d -2,0
		{
			while (args->wid-- > 0)
				args->res += ft_putchar(' ');
			return (args->res);
		}
		if ((args->width > 0 || args->star_width > 0) && (args->has_prec || args->has_star_prec) &&
				(args->prec == 0 || args->star_prec == 0) && d == 0) // pour %*.*d  -2, 0, 5
			// A METTRE DANS UNE FONCTION ET FAIRE UNE FCT CHECK QUI LES REGROUPE TOUTES
		{
			while (args->wid-- > 0)
				args->res += ft_putchar(' ');
			return (args->res);
		}
		if (args->wid < 0)
		{
			args->wid *= -1;
			args->minus = 1;
		}
		tmp = ft_itoa_base(d, base);
		args->len = ft_strlen(tmp);
		if (ft_check_full_zero(args, d))
			return (0);
		if (ft_check_prec_null_long(args, d))
			return (0);
		if (d < 0)
		{
			if ((args->len - 1) < args->precision)
				args->padding = (args->precision - (args->len - 1));
			else
				args->padding = 0;
		}
		else
		{
			if (args->len < args->precision)
				args->padding = (args->precision - args->len);
			else
				args->padding = 0;
		}
		args->len += args->padding;
		if (args->zero)
		{
			if (args->has_prec || args->has_star_prec)
			{
				while ((args->wid - args->len) > 0)
				{
					args->res += ft_putchar(' ');
					args->wid--;
				}
				args->res += ft_put_X_zero(tmp, args);
				return (args->res);
			}
			else
			{
				if (d < 0)
					args->padding = (args->len - 1) < args->wid ? (args->wid - (args->len)) : 0;
				else
					args->padding = args->len < args->wid ? (args->wid - args->len) : 0;
				args->res += ft_put_X_zero(tmp, args);
				return (args->res);
			}
		}
		if (args->minus)
		{
			args->res += ft_put_X_zero(tmp, args);
			while ((args->wid - args->len) > 0)
			{
				args->res += ft_putchar(' ');
				args->wid--;
			}
			return (args->res);
		}
		while ((args->wid - args->len) > 0)
		{
			args->res += ft_putchar(' ');
			args->wid--;
		}
		return (args->res + ft_put_X_zero(tmp, args));
	}


	// ---------- xxxxxxxxxxxx --------------

	int		ft_put_x_zero(char *str, t_args *args)
	{
		int res;

		res = 0;
		while (args->padding-- > 0)
			res += ft_putchar('0');
		if (args->prec_null == 0)
			res += ft_putstr(str);
		else
			res += ft_putchar(' ');
		return (res);
	}


	int	ft_check_args_put_x(t_args *args, long d)
	{
		if (args->has_width == -1 && d == 0)
			args->res += ft_putchar('0');
		if (args->has_width && args->width == 1 && d != 0)
		{
			args->has_width = 0;
			args->width = -1;
		}
		if (!args->has_star_width && args->has_star_prec && args->star_prec < 0 && d == 0)
		{
			args->res += ft_putchar('0');
			return (args->res);
		}
		if (args->has_prec && args->prec == -1 && d == 0 && args->has_star_width && args->star_width > -1) // pour %*.d -2,0
		{
			while (args->wid-- > 0)
				args->res += ft_putchar(' ');
			return (args->res);
		}
		if ((args->width > 0 || args->star_width > 0) && (args->has_prec || args->has_star_prec) &&
				(args->prec == 0 || args->star_prec == 0) && d == 0) // pour %*.*d  -2, 0, 5
			// A METTRE DANS UNE FONCTION ET FAIRE UNE FCT CHECK QUI LES REGROUPE TOUTES
		{
			while (args->wid-- > 0)
				args->res += ft_putchar(' ');
			return (args->res);
		}
		if (args->wid < 0)
		{
			args->wid *= -1;
			args->minus = 1;
		}
		return (0);
	}


	int		ft_put_x(t_args *args, va_list ap)
	{
		long d;
		char *tmp;
		char *base;
		int fautilreturn;


		base = "0123456789abcdef";
		if (args->has_width && args->has_prec && (args->prec == -1 || args->prec == 0))
			args->prec_null = 1; //pour %5.0i et 5.i   avec i = 0
		ft_init_width_prec_starwid_starprec(args);
		d = (long)va_arg(ap, unsigned int);
		fautilreturn = ft_check_args_put_x(args, d);
		if (ft_check_args_put_x(args, d) != 0)
			return (fautilreturn);
		tmp = ft_itoa_base(d, base);
		args->len = ft_strlen(tmp);
		if (ft_check_full_zero(args, d))
			return (0);
		if (ft_check_prec_null_int(args, d))
			return (0);
		if (d < 0)
		{
			if ((args->len - 1) < args->precision)
				args->padding = (args->precision - (args->len - 1));
			else
				args->padding = 0;
		}
		else
		{
			if (args->len < args->precision)
				args->padding = (args->precision - args->len);
			else
				args->padding = 0;
		}
		args->len += args->padding;
		if (args->zero)
		{
			if (args->has_prec || args->has_star_prec)
			{
				while ((args->wid - args->len) > 0)
				{
					args->res += ft_putchar(' ');
					args->wid--;
				}
				args->res += ft_put_x_zero(tmp, args);
				return (args->res);
			}
			else
			{
				if (d < 0)
					args->padding = (args->len - 1) < args->wid ? (args->wid - (args->len)) : 0;
				else
					args->padding = args->len < args->wid ? (args->wid - args->len) : 0;
				args->res += ft_put_x_zero(tmp, args);
				return (args->res);
			}
		}
		if (args->minus)
		{
			args->res += ft_put_x_zero(tmp, args);
			while ((args->wid - args->len) > 0)
			{
				args->res += ft_putchar(' ');
				args->wid--;
			}
			return (args->res);
		}
		while ((args->wid - args->len) > 0)
		{
			args->res += ft_putchar(' ');
			args->wid--;
		}
		return (args->res + ft_put_x_zero(tmp, args));
	}


	// ----------- sssssssss ------------
	int		ft_put_s(t_args *args, va_list ap)
	{
		char *s;

		ft_init_width_prec_starwid_starprec(args);
		s = va_arg(ap, char *);
		if (!s)
			s = "(null)";
		if (!args->has_width && !args->has_star_width && args->star_prec == 0)
			return (0);
		args->len = ft_strlen(s);
		if (args->has_prec && args->has_star_prec && args->star_prec < 0)
			return (args->res + ft_putstr(s));
		if (args->has_prec || args->has_star_prec)
		{
			if (args->precision == -1)
				args->len = 0;
			else if (args->len > args->precision)
				args->len = args->precision;
		}
		if (args->minus)
		{
			args->res += ft_putstrl(s,args->len);
			while ((args->wid - args->len) > 0)
			{
				args->res += ft_putchar(' ');
				args->wid--;
			}
			return (args->res);
		}
		else
		{
			while ((args->wid - args->len) > 0)
			{
				args->res += ft_putchar(' ');
				args->wid--;
			}
			if (args->has_prec || args->has_star_prec)
			{
				while (*s && args->precision-- > 0)
				{
					args->res += ft_putchar(*s);
					s++;
				}
				return (args->res);
			}
		}
		return (args->res + ft_putstrl(s, args->len));
	}

	// ----------- cccccccccc ----------------

	int		ft_put_c(t_args *args, va_list ap)
	{
		int c;

		c = va_arg(ap, int);
		ft_init_width_prec_starwid_starprec(args);
		if (args->minus)
		{
			args->res += ft_putchar(c + 0);
			while (args->wid > 1)
			{
				args->res += ft_putchar(' ');
				args->wid--;
			}
			return (args->res);
		}
		else
		{
			while (args->wid > 1)
			{
				args->res += ft_putchar(' ');
				args->wid--;
			}
		}
		return (args->res + ft_putchar(c + 0));
	}

	// ----------- ppppcccccctttttt ----------


	int		ft_put_pct(t_args *args, va_list ap)
	{
		(void)ap;

		if (args->has_width)
			args->wid = args->width;
		else
			args->wid = 0;
		args->res = 0;
		if (args->minus == 1)
		{
			args->res += ft_putchar('%');
			while (args->wid > 1)
			{
				args->res += ft_putchar(' ');
				args->wid--;
			}
			return (args->res);
		}
		else
		{
			if (args->zero)
			{
				while (args->wid > 1)
				{
					args->res += ft_putchar('0');
					args->wid--;
				}
			}
			else
			{
				while (args->wid > 1)
				{
					args->res += ft_putchar(' ');
					args->wid--;
				}
			}
		}
		return (args->res + ft_putchar('%'));

	}

	// ------------ uuuuuuuuu -------------

	int		ft_put_u_zero(unsigned int d, t_args *args)
	{
		int res;

		res =0;
		if (d == 4294967295)
		{
			while (args->padding-- > 0)
				res += ft_putchar('0');
			res += ft_putstr("4294967295");
			return (res);
		}
		while (args->padding-- > 0)
			res += ft_putchar('0');
		if (d / 10)
			res += ft_put_u_zero(d / 10, args);
		if (args->prec_null == 0)
			res += ft_putchar((d % 10) + '0');
		else
			res += ft_putchar(' ');
		return (res);
	}

	int		ft_put_u(t_args *args, va_list ap)
	{
		unsigned int d;

		if (args->has_width && args->has_prec && (args->prec == -1 || args->prec == 0))
			args->prec_null = 1; //pour %5.0i et 5.i   avec i = 0
		ft_init_width_prec_starwid_starprec(args);
		d = va_arg(ap, unsigned int);
		if (args->has_width == -1 && d == 0)
			args->res += ft_putchar('0');
		if (args->has_width && args->width == 1 && d != 0)
		{
			args->has_width = 0;
			args->width = -1;
		}
		if (!args->has_star_width && args->has_star_prec && args->star_prec < 0 && d == 0)
		{
			args->res += ft_putchar('0');
			return (args->res);
		}
		if (args->has_prec && args->prec == -1 && d == 0 && args->has_star_width && args->star_width > -1) // pour %*.d -2,0
		{
			while (args->wid-- > 0)
				args->res += ft_putchar(' ');
			return (args->res);
		}
		if ((args->width > 0 || args->star_width > 0) && (args->has_prec || args->has_star_prec) &&
				(args->prec == 0 || args->star_prec == 0) && d == 0) // pour %*.*d  -2, 0, 5
			// A METTRE DANS UNE FONCTION ET FAIRE UNE FCT CHECK QUI LES REGROUPE TOUTES
		{
			while (args->wid-- > 0)
				args->res += ft_putchar(' ');
			return (args->res);
		}
		if (args->has_width == -1 && d == 0)
			args->res += ft_putchar('0');
		if (ft_check_full_zero(args, d))
			return (0);
		if (ft_check_prec_null_int(args, d))
			return (0);
		args->len = ft_nb_digits_unsigned(d);
		if (args->len < args->precision)
			args->padding = (args->precision - args->len);
		else
			args->padding = 0;
		args->len += args->padding;
		if (args->zero)
		{
			if (args->has_prec || args->has_star_prec)
			{
				while ((args->wid - args->len) > 0)
				{
					args->res += ft_putchar(' ');
					args->wid--;
				}
				args->res += ft_put_u_zero(d, args);
				return (args->res);
			}
			else
			{
				if (d < 0)
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
				args->res += ft_put_u_zero(d, args);
				return (args->res);
			}
		}
		if (args->minus)
		{
			args->res += ft_put_u_zero(d, args);
			while ((args->wid - args->len) > 0)
			{
				args->res += ft_putchar(' ');
				args->wid--;
			}
			return (args->res);
		}
		while ((args->wid - args->len) > 0)
		{
			args->res += ft_putchar(' ');
			args->wid--;
		}
		return (args->res + ft_put_u_zero(d, args));
	}



	//dddddddddddddddddddddddddddddddddd



	int		ft_put_d_zero(int d, t_args *args)
	{
		int res;

		res = 0;
		if (d == -2147483648)
		{
			res += ft_putchar('-');
			while (args->padding-- > 0)
				res += ft_putchar('0');
			res += ft_putstr("2147483648");
			return (res);
		}
		if (d < 0)
		{
			res += ft_putchar('-');
			d *= -1;
		}
		while (args->padding-- > 0)
			res += ft_putchar('0');
		if (d / 10)
			res += ft_put_d_zero(d / 10, args);
		if (args->prec_null == 0)
			res += ft_putchar((d % 10) + '0');
		else
		{
			res += ft_putchar(' ');
		}
		return (res);
	}

	int		ft_put_d(t_args *args, va_list ap)
	{
		int d;

		//METTRE LA FONCTION DINITATLISATION args->wid PREC ICI
		ft_init_width_prec_starwid_starprec(args);
		//	printf("wid = %d  precision = %d  width = %d  prec = %d\n", args->wid, args->precision, args->width, args->prec);
		//	printf("starwid = %d  starprecision = %d  star_width = %d  star_prec = %d\n", args->wid, args->precision, args->star_width, args->star_prec);
		d = va_arg(ap, int);
		if (args->has_width && args->has_prec && d ==0 && (args->prec == -1 || args->prec == 0))
			args->prec_null = 1; //pour %5.0i et 5.i   avec i = 0
		if (args->has_width == -1 && d == 0)
			args->res += ft_putchar('0');
		if (args->has_width && args->width == 1 && d != 0)
		{
			args->has_width = 0;
			args->width = -1;
		}
		if (!args->has_star_width && args->has_star_prec && args->star_prec < 0 && d == 0)
		{
			args->res += ft_putchar('0');
			return (args->res);
		}
		if (args->has_prec && args->prec == -1 && d == 0 && args->has_star_width && args->star_width > -1) // pour %*.d -2,0
		{
			while (args->wid-- > 0)
				args->res += ft_putchar(' ');
			return (args->res);
		}
		if ((args->width > 0 || args->star_width > 0) && (args->has_prec || args->has_star_prec) &&
				(args->prec == 0 || args->star_prec == 0) && d == 0) // pour %*.*d  -2, 0, 5
			// A METTRE DANS UNE FONCTION ET FAIRE UNE FCT CHECK QUI LES REGROUPE TOUTES
		{
			while (args->wid-- > 0)
				args->res += ft_putchar(' ');
			return (args->res);
		}

		if (ft_check_full_zero(args, d))
			return (0);
		if (ft_check_prec_null_int(args, d))
			return (0);
		args->len = ft_nb_digits(d);
		if (d < 0)
		{
			if ((args->len - 1) < args->precision)
				args->padding = (args->precision - (args->len - 1));
			else
				args->padding = 0;
		}
		else
		{
			if (args->len < args->precision)
				args->padding = (args->precision - args->len);
			else
				args->padding = 0;
		}
		args->len += args->padding;
		if (args->zero)
		{
			if (args->has_prec || args->has_star_prec)
			{
				while ((args->wid - args->len) > 0)
				{
					args->res += ft_putchar(' ');
					args->wid--;
				}
				args->res += ft_put_d_zero(d, args);
				return (args->res);
			}
			else
			{
				if (d < 0)
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
				args->res += ft_put_d_zero(d, args);
				return (args->res);
			}
		}
		if (args->minus)
		{
			args->res += ft_put_d_zero(d, args);
			while ((args->wid - args->len) > 0)
			{
				args->res += ft_putchar(' ');
				args->wid--;
			}
			return (args->res);
		}
		while ((args->wid - args->len) > 0)
		{
			args->res += ft_putchar(' ');
			args->wid--;
		}
		return (args->res + ft_put_d_zero(d, args));
	}


	// ----------- iiiiiiiiiii ---------




	int		ft_put_i_zero(int d, t_args *args)
	{
		int res;

		res = 0;
		if (d == -2147483648)
		{
			res += ft_putchar('-');
			while (args->padding-- > 0)
				res += ft_putchar('0');
			res += ft_putstr("2147483648");
			return (res);
		}
		if (d < 0)
		{
			res += ft_putchar('-');
			d *= -1;
		}
		while (args->padding-- > 0)
			res += ft_putchar('0');
		if (d / 10)
			res += ft_put_i_zero(d / 10, args);
		if (args->prec_null == 0)
			res += ft_putchar((d % 10) + '0');
		else
			res += ft_putchar(' ');
		return (res);
	}






	int		ft_put_i(t_args *args, va_list ap)
	{
		int d;

		ft_init_width_prec_starwid_starprec(args);
		d = va_arg(ap, int);
		if (args->has_width && args->has_prec && d ==0 && (args->prec == -1 || args->prec == 0))
			args->prec_null = 1; //pour %5.0i et 5.i   avec i = 0
		if (args->has_width == -1 && d == 0)
			args->res += ft_putchar('0');
		if (args->has_width && args->width == 1 && d != 0)
		{
			args->has_width = 0;
			args->width = -1;
		}
		if (!args->has_star_width && args->has_star_prec && args->star_prec < 0 && d == 0)
		{
			args->res += ft_putchar('0');
			return (args->res);
		}
		if (args->has_prec && args->prec == -1 && d == 0 && args->has_star_width && args->star_width > -1)
		{
			while (args->wid-- > 0)
				args->res += ft_putchar(' ');
			return (args->res);
		}

		if (ft_check_full_zero(args, d))
			return (0);
		if (ft_check_prec_null_int(args, d))
			return (0);
		args->len = ft_nb_digits(d);
		if (d < 0)
		{
			if ((args->len - 1) < args->precision)
				args->padding = (args->precision - (args->len - 1));
			else
				args->padding = 0;
		}
		else
		{
			if (args->len < args->precision)
				args->padding = (args->precision - args->len);
			else
				args->padding = 0;
		}
		args->len += args->padding;
		if (args->zero)
		{
			if (args->has_prec || args->has_star_prec)
			{
				while ((args->wid - args->len) > 0)
				{
					args->res += ft_putchar(' ');
					args->wid--;
				}
				args->res += ft_put_i_zero(d, args);
				return (args->res);
			}
			else
			{
				if (d < 0)
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
				args->res += ft_put_i_zero(d, args);
				return (args->res);
			}
		}
		if (args->minus)
		{
			args->res += ft_put_i_zero(d, args);
			while ((args->wid - args->len) > 0)
			{
				args->res += ft_putchar(' ');
				args->wid--;
			}
			return (args->res);
		}
		while ((args->wid - args->len) > 0)
		{
			args->res += ft_putchar(' ');
			args->wid--;
		}
		return (args->res + ft_put_i_zero(d, args));
	}

	int	ft_put_conv(t_args *args, va_list ap)
	{
		if (args->c == 'c')
			return (ft_put_c(args, ap));
		else if (args->c == 's')
			return (ft_put_s(args, ap));
		else if (args->c == 'd')
			return (ft_put_d(args,ap));
		else if (args->c == 'p')
			return (ft_put_p(args, ap));
		else if (args->c == 'i')
			return (ft_put_i(args, ap));
		else if (args->c == 'u')
			return (ft_put_u(args, ap));
		else if (args->c == 'x')
			return (ft_put_x(args, ap));
		else if (args->c == 'X')
			return (ft_put_X(args, ap));
		else if (args->c == '%')
			return (ft_put_pct(args, ap));
		return (0);
	}

	int	ft_printf(const char *format, ...)
	{
		char	*itr;
		t_args	args;
		va_list	ap;
		int res;

		itr = (char *)format;
		if (!itr)
			return (0);
		res = 0;
		va_start(ap, format);
		while (*itr)
		{
			if (*itr == '%')
			{
				itr = read_args(&args, itr, ap);
				res += ft_put_conv(&args, ap);
				continue ;
			}
			res += ft_putchar(*itr);
			itr++;
		}
		va_end(ap);
		return (res);
	}

