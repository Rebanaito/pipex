/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:55:23 by revanite          #+#    #+#             */
/*   Updated: 2023/05/26 11:58:26 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	putchar_str(char c, char *s);
static void	putnbr_str(unsigned long long int n, char *s);

char	*ft_itoa_ull(unsigned long long int n)
{
	char	*str;
	char	buff[50];

	ft_bzero(buff, 50);
	putnbr_str(n, buff);
	str = (char *)ft_calloc(sizeof(char), ft_strlen(buff) + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, buff);
	return (str);
}

static void	putnbr_str(unsigned long long int n, char *s)
{
	if (n > 9)
		putnbr_str(n / 10, s);
	putchar_str('0' + (n % 10), s);
}

static void	putchar_str(char c, char *s)
{
	while (*s)
		s++;
	*s = c;
}
