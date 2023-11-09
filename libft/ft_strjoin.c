/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 03:31:48 by fda-estr          #+#    #+#             */
/*   Updated: 2023/09/25 02:00:27 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	sj = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!sj)
		return (NULL);
	if (s1)
		ft_strlcpy(sj, s1, s1len + 1);
	if (s2)
		ft_strlcat(sj, s2, (s1len + s2len + 1));
	return (sj);
}
