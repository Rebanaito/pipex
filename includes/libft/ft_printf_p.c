/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:03:21 by revanite          #+#    #+#             */
/*   Updated: 2023/06/19 09:00:34 by ekolosov         ###   ########.fr       */
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
	while (f > len + plus && ((p - f + plus) < 0))
		print_field(s, c, &f);
	if (d && s->hash && (s->specifier == 'x' || s->specifier == 'X'))
		print_prefix(s, c);
	if (d && s->hash && s->specifier == 'o')
		putchar_counter('0', c);
}

static void	null(t_spec *spec, int *c)
{
	if (!(spec->left_justify))
		print_padding(spec, c, 5, 0);
	ft_putstr("(nil)");
	*c += 5;
	if (spec->left_justify)
		print_padding(spec, c, 5, 0);
}

void	pntr(t_spec *spec, int *c, va_list l, char *(*f)(unsigned long long))
{
	void	*p;
	char	*str;

	p = va_arg(l, void *);
	if (p == NULL)
	{
		null(spec, c);
		return ;
	}
	str = f((unsigned long long)p);
	if (str == NULL)
		return ;
	if (!(spec->left_justify))
		print_padding(spec, c, (long long)ft_strlen(str) + 2, 0);
	ft_str_tolower(str);
	ft_putstr("0x");
	ft_putstr(str);
	if (spec->left_justify)
		print_padding(spec, c, (long long)ft_strlen(str) + 2, 0);
	*c += ft_strlen(str) + 2;
	free(str);
}
