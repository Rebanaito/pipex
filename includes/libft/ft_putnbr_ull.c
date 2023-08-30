/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 04:38:43 by revanite          #+#    #+#             */
/*   Updated: 2023/05/19 05:26:50 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putnbr_ull(unsigned long long int n)
{
	if (n > 9)
		ft_putnbr_ull(n / 10);
	ft_putchar_fd('0' + (n % 10), 1);
}
