/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 05:34:09 by revanite          #+#    #+#             */
/*   Updated: 2023/05/26 11:51:45 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	putchar_str(char c, char *s);
static void	putnbr_str(int n, char *s);

char	*ft_itoa(int n)
{
	char	*str;
	char	buff[12];

	ft_bzero(buff, 12);
	putnbr_str(n, buff);
	str = (char *)ft_calloc(sizeof(char), ft_strlen(buff) + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, buff);
	return (str);
}

static void	putnbr_str(int n, char *s)
{
	if (n < -9 || n > 9)
		putnbr_str(n / 10, s);
	if (n < 0)
	{
		if (n >= -9)
			putchar_str('-', s);
		putchar_str('0' - (n % 10), s);
	}
	else
		putchar_str('0' + (n % 10), s);
}

static void	putchar_str(char c, char *s)
{
	while (*s)
		s++;
	*s = c;
}
