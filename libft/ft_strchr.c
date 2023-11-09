/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 03:36:00 by fda-estr          #+#    #+#             */
/*   Updated: 2023/04/20 20:37:03 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

//{		
	// if (c == 0)
	// 	return ((char *) s);
	// while (*s && *s != (char)c)
	// 	s++;
	// if (*s == (char)c)
	// 	return ((char *)s);
	// //if (*s == 0)
	// 	return (NULL);
//}
// #include <stdio.h>

// int main()
// {
// 	char *s = "Francisco";
// 	printf("%s\n", ft_strchr(s, 'i'));
// }