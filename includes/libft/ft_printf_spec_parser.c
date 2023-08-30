/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:14:45 by revanite          #+#    #+#             */
/*   Updated: 2023/06/19 09:01:11 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	valid_flag(char c, t_spec *spec)
{
	if (ft_strchr("-0# +", c))
	{
		if (c == '-')
			spec->left_justify = 1;
		else if (c == '0')
			spec->zero_pad = 1;
		else if (c == '#')
			spec->hash = 1;
		else if (c == ' ')
			spec->space = 1;
		else if (c == '+')
			spec->plus = '+';
		return (1);
	}
	return (0);
}

static int	valid_length(char c, t_spec *spec)
{
	if (!(spec->length))
	{
		if (c == 'h' || c == 'l')
		{
			spec->length = c;
			return (1);
		}
		else
			return (0);
	}
	if (c == 'h' && spec->length == 'h')
	{
		spec->length = 'H';
		return (1);
	}
	else if (c == 'l' && spec->length == 'l')
	{
		spec->length = 'L';
		return (1);
	}
	return (0);
}

static int	valid_specifier(char c, t_spec *spec)
{
	if (ft_strchr("cspdiuoxX%", c))
	{
		spec->specifier = c;
		return (1);
	}
	return (0);
}

void	dot(const char **s, t_spec *spec)
{
	spec->dot = 1;
	while (ft_isdigit(*(++(*s))))
		spec->precision = spec->precision * 10 + (**s - '0');
}

void	handle_specifier(const char **s, int *count, va_list list)
{
	char	*start;
	t_spec	spec;

	null_spec(&spec);
	start = (char *)(*s)++;
	while (valid_flag(**s, &spec))
		(*s)++;
	while (ft_isdigit(**s))
		spec.field = spec.field * 10 + (*(*s)++ - '0');
	if (**s == '.')
		dot(s, &spec);
	while (valid_length(**s, &spec))
		(*s)++;
	if (valid_specifier(**s, &spec))
		(*s)++;
	else
	{
		while (start <= *s)
			ft_putchar_fd(*start++, 1);
		(*s)++;
		return ;
	}
	print_specifier(&spec, count, list);
}
