/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prcnt_mac.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 07:52:35 by revanite          #+#    #+#             */
/*   Updated: 2023/06/19 09:00:39 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	prcnt(t_spec *spec, int *count)
{
	if (!(spec->left_justify))
	{
		while ((spec->field)-- > 1)
		{
			ft_putchar_fd(' ', 1);
			(*count)++;
		}
		ft_putchar_fd('%', 1);
	}
	else
	{
		ft_putchar_fd('%', 1);
		while ((spec->field)-- > 1)
		{
			ft_putchar_fd(' ', 1);
			(*count)++;
		}
	}
	(*count)++;
}
