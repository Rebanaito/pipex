/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:40:03 by revanite          #+#    #+#             */
/*   Updated: 2023/06/19 09:01:06 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	print_sign(t_spec *spec, int *c, long long d)
{
	if (d >= 0 && spec->plus)
		putchar_counter('+', c);
	else if (d >= 0 && spec->space)
		putchar_counter(' ', c);
	else if (spec->plus == '-')
		putchar_counter('-', c);
}

static void	print_padding(t_spec *s, int *c, long long len, long long d)
{
	long long int	p;
	long long int	f;
	int				plus;

	p = s->precision;
	f = s->field;
	plus = 0;
	if ((s->plus == '-' && d != 0) || s->plus == '+' || s->space)
		plus = 1;
	while (f > len + plus && ((p - f + plus) < 0))
		print_field(s, c, &f);
	s->field = f;
}

static void	left(t_spec *spec, int *c, char *str, long long d)
{
	unsigned long	len;

	len = (unsigned long)ft_strlen(str);
	if (!d && spec->dot && !(spec->precision))
		len = 0;
	print_sign(spec, c, d);
	zeroes(spec, c, len);
	if (!(spec->dot) || spec->precision || d)
	{
		ft_putstr(str);
		*c += len;
	}
	print_padding(spec, c, len, d);
}

static void	right(t_spec *spec, int *c, char *str, long long d)
{
	unsigned long	len;
	int				plus;

	plus = 0;
	if (spec->plus || spec->space)
		plus = 1;
	len = (unsigned long)ft_strlen(str);
	if (!d && spec->dot && !(spec->precision))
		len = 0;
	if (!(spec->zero_pad) || spec->dot)
		print_padding(spec, c, len, d);
	print_sign(spec, c, d);
	if (spec->zero_pad && spec->field > spec->precision + len + plus)
		print_padding(spec, c, len, d);
	zeroes(spec, c, len);
	if (!(spec->dot) || (spec->precision) || d)
	{
		ft_putstr(str);
		*c += ft_strlen(str);
	}
}

void	sign(t_spec *spec, int *c, va_list l, char *(*f)(long long))
{
	long long int	d;
	char			*str;

	if (spec->length == 'l')
		d = va_arg(l, long int);
	else if (spec->length == 'L')
		d = va_arg(l, long long int);
	else
		d = va_arg(l, int);
	if (d < 0)
		spec->plus = '-';
	str = f(d);
	if (str == NULL)
		return ;
	if (!(spec->left_justify))
		right(spec, c, str, d);
	else
		left(spec, c, str, d);
	free(str);
}
