/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 05:38:25 by revanite          #+#    #+#             */
/*   Updated: 2023/06/19 09:01:57 by ekolosov         ###   ########.fr       */
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

void	zeroes(t_spec *spec, int *c, unsigned long len)
{
	while (spec->precision > len)
	{
		putchar_counter('0', c);
		(spec->precision)--;
		if (spec->field)
			(spec->field)--;
	}
}

void	hash(t_spec *spec, int *c, unsigned long len, unsigned long long d)
{
	if (spec->precision >= spec->field || len > spec->field
		|| (spec->zero_pad && !(spec->dot)))
	{
		print_prefix(spec, c);
		print_padding(spec, c, len, d);
	}
	else
	{
		print_padding(spec, c, len, d);
		print_prefix(spec, c);
	}
}

void	ft_putnstr(const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] && i < n)
		write(1, &s[i++], 1);
}
