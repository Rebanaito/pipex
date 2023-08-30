/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:40:03 by revanite          #+#    #+#             */
/*   Updated: 2023/06/19 09:01:16 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	print_padding(t_spec *s, int *c, long long len, long long d)
{
	long long int	p;
	long long int	f;
	int				plus;

	p = s->precision;
	f = s->field;
	plus = 0;
	if (s->plus == '+')
		plus = 1;
	if (d && s->hash && (s->specifier == 'x' || s->specifier == 'X'))
		f -= 2;
	else if (d && s->specifier == 'o' && s->hash)
		f--;
	while (f > len + plus && ((p - f + plus) < 0))
		print_field(s, c, &f);
	if (d && s->hash && s->specifier == 'o')
		putchar_counter('0', c);
}

static void	right(t_spec *spec, int *c, char *str, unsigned long long d)
{
	unsigned long	len;
	int				hsh;

	len = (unsigned long)ft_strlen(str);
	if (!d && spec->dot && !(spec->precision))
		len = 0;
	hsh = 0;
	if (d && spec->hash && (spec->specifier == 'x' || spec->specifier == 'X'))
		hsh = 1;
	if (hsh)
		hash(spec, c, len, d);
	else
		print_padding(spec, c, len, d);
	zeroes(spec, c, len);
	if (!(spec->dot) || (spec->precision) || d)
	{
		ft_putstr(str);
		*c += len;
	}
	free(str);
}

static void	left(t_spec *spec, int *c, char *str, unsigned long long d)
{
	unsigned long	len;

	len = (unsigned long)ft_strlen(str);
	if (!d && spec->dot && !(spec->precision))
		len = 0;
	if (d && spec->hash && (spec->specifier == 'x' || spec->specifier == 'X'))
		print_prefix(spec, c);
	zeroes(spec, c, len);
	if (!(spec->dot) || (spec->precision) || d)
	{
		ft_putstr(str);
		*c += len;
	}
	print_padding(spec, c, len, d);
	free(str);
}

void	usgn(t_spec *spec, int *c, va_list l, char *(*f)(unsigned long long))
{
	unsigned long long int	d;
	char					*str;

	if (spec->length == 'l')
		d = va_arg(l, unsigned long int);
	else if (spec->length == 'L')
		d = va_arg(l, unsigned long long int);
	else
		d = va_arg(l, unsigned int);
	str = f(d);
	if (str == NULL)
		return ;
	if (spec->specifier == 'x')
		ft_str_tolower(str);
	if (!(spec->left_justify))
		right(spec, c, str, d);
	else
		left(spec, c, str, d);
}
