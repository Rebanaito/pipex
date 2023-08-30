/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 10:58:23 by revanite          #+#    #+#             */
/*   Updated: 2023/06/19 09:01:31 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	null_spec(t_spec *spec)
{
	spec->left_justify = 0;
	spec->zero_pad = 0;
	spec->precision = 0;
	spec->field = 0;
	spec->hash = 0;
	spec->space = 0;
	spec->plus = 0;
	spec->length = 0;
	spec->specifier = 0;
	spec->dot = 0;
}

void	print_specifier(t_spec *spec, int *count, va_list list)
{
	if (spec->specifier == 'c')
		ft_printf_c(spec, count, list);
	else if (spec->specifier == 'd')
		sign(spec, count, list, *ft_itoa_ll);
	else if (spec->specifier == 'i')
		sign(spec, count, list, *ft_itoa_ll);
	else if (spec->specifier == 'o')
		usgn(spec, count, list, *ft_itoa_oct);
	else if (spec->specifier == 'p')
	{
		spec->hash = 1;
		pntr(spec, count, list, *ft_itoa_hex);
	}
	else if (spec->specifier == 's')
		ft_printf_s(spec, count, list);
	else if (spec->specifier == 'u')
		usgn(spec, count, list, *ft_itoa_ull);
	else if (spec->specifier == 'x' || spec->specifier == 'X')
		usgn(spec, count, list, *ft_itoa_hex);
	else if (spec->specifier == '%')
		prcnt(spec, count);
}

void	putchar_counter(char c, int *counter)
{
	ft_putchar_fd(c, 1);
	(*counter)++;
}

void	print_prefix(t_spec *s, int *c)
{
	if (s->specifier == 'x')
		ft_putstr("0x");
	else
		ft_putstr("0X");
	*c += 2;
}

void	print_field(t_spec *s, int *c, long long *f)
{
	if (s->zero_pad && !(s->dot))
		putchar_counter('0', c);
	else
		putchar_counter(' ', c);
	(*f)--;
}
