/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:49:53 by revanite          #+#    #+#             */
/*   Updated: 2023/06/19 09:01:01 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	print_null(int *count, long long *f)
{
	ft_putstr("(null)");
	*count += 6;
	if (f != NULL)
		*f -= 6;
}

static void	right(t_spec *spec, int *count, char *str, long long len)
{
	long long	f;

	f = spec->field;
	if (str || (!str && spec->dot))
		while (f-- > len)
			putchar_counter(' ', count);
	else
		while (f-- > len)
			putchar_counter(' ', count);
	if (str == NULL)
	{
		if (!(spec->dot) || spec->precision >= 6)
			print_null(count, NULL);
	}
	else
	{
		while ((!(spec->dot) && len) || (spec->dot && spec->precision && len))
		{
			putchar_counter(*str++, count);
			(spec->precision)--;
			len--;
		}
	}
}

static void	left(t_spec *spec, int *count, char *str, long long len)
{
	long long	f;

	f = spec->field;
	if (str == NULL)
	{
		if (!(spec->dot) || spec->precision >= 6)
			print_null(count, &f);
	}
	else
	{
		while ((!(spec->dot) && len) || (spec->dot && spec->precision && len))
		{
			putchar_counter(*str++, count);
			(spec->precision)--;
			len--;
			f--;
		}
	}
	while (f-- > 0)
		putchar_counter(' ', count);
}

void	ft_printf_s(t_spec *spec, int *count, va_list list)
{
	long long	len;
	char		*str;

	if (spec->length == 'l' || spec->length == 'L')
		return ;
	str = va_arg(list, char *);
	if (str == NULL && spec->dot && spec->precision >= 6)
		len = 6;
	else if (str == NULL && !(spec->dot))
		len = 6;
	else if (str == NULL)
		len = 0;
	else if (spec->dot && spec->precision < ft_strlen(str))
		len = spec->precision;
	else
		len = ft_strlen(str);
	if (!(spec->left_justify))
		right(spec, count, str, len);
	else
		left(spec, count, str, len);
}
