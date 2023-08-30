/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:09:59 by revanite          #+#    #+#             */
/*   Updated: 2023/05/26 12:10:31 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putnbr_ll(long long int n)
{
	if (n < -9 || n > 9)
		ft_putnbr_ll(n / 10);
	if (n < 0)
	{
		if (n >= -9)
			ft_putchar_fd('-', 1);
		ft_putchar_fd('0' - (n % 10), 1);
	}
	else
		ft_putchar_fd('0' + (n % 10), 1);
}
