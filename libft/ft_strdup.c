/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 03:40:59 by fda-estr          #+#    #+#             */
/*   Updated: 2023/04/22 06:21:25 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Substituir o loop while pelo strlen dentro do malloc:
// ns = malloc(sizeof(char) * ft_strlen(s));

char	*ft_strdup(const char *s)
{
	unsigned char	*ns;
	int				i;
	int				len;

	i = 0;
	len = ft_strlen(s);
	ns = ft_calloc(sizeof(char), (len + 1));
	if (!ns)
		return (NULL);
	while (s[i])
	{
		ns[i] = s[i];
		i++;
	}
	return ((char *) ns);
}
