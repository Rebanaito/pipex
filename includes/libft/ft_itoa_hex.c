/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:53:09 by revanite          #+#    #+#             */
/*   Updated: 2023/05/27 01:20:42 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	putchar_str_hex(char c, char *s);
static void	putnbr_str_hex(unsigned long long int n, char *s);

char	*ft_itoa_hex(unsigned long long int n)
{
	char	*str;
	char	buff[50];

	ft_bzero(buff, 50);
	putnbr_str_hex(n, buff);
	str = (char *)ft_calloc(sizeof(char), ft_strlen(buff) + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, buff);
	return (str);
}

static void	putnbr_str_hex(unsigned long long int n, char *s)
{
	if (n > 15)
		putnbr_str_hex(n / 16, s);
	putchar_str_hex('0' + (n % 16), s);
}

static void	putchar_str_hex(char c, char *s)
{
	while (*s)
		s++;
	if ((c >= 48 && c <= 57))
		*s = c;
	else
		*s = c + 7;
}
