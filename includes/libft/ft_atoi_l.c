/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 08:55:46 by revanite          #+#    #+#             */
/*   Updated: 2023/06/24 05:46:45 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

long	ft_atoi_l(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	while (ft_isdigit(*str))
		num = num * 10 + (*str++ - '0');
	num *= sign;
	return (num);
}
