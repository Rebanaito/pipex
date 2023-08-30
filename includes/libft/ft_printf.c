/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:53:44 by revanite          #+#    #+#             */
/*   Updated: 2023/06/22 11:33:14 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_printf(const char *s, ...)
{
	int				count;
	va_list			list;

	count = 0;
	va_start(list, s);
	while (*s)
	{
		while (*s && *s != '%')
		{
			ft_putchar_fd(*s++, 1);
			count++;
		}
		if (*s == '%')
			handle_specifier(&s, &count, list);
	}
	va_end(list);
	return (count);
}
