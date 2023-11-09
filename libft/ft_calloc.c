/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:08:46 by fda-estr          #+#    #+#             */
/*   Updated: 2023/04/19 18:27:56 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*s;

	s = malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_bzero(s, size * nmemb);
	return (s);
}
