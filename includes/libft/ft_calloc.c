/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:13:03 by revanite          #+#    #+#             */
/*   Updated: 2023/05/18 11:29:14 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t nmemb, size_t n)
{
	void	*p;

	p = malloc(nmemb * n);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, nmemb * n);
	return (p);
}
