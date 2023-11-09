/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:00:34 by fda-estr          #+#    #+#             */
/*   Updated: 2023/04/23 18:32:59 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (start >= ft_strlen(s))
		sub = malloc(1);
	else if (len >= ft_strlen(s))
		sub = malloc(ft_strlen(s) - start + 1);
	else
		sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = 0;
	return (sub);
}

// int main()
// {
// 	char	str[] = "Francisco Miguel da Estrela Inacio";
// 	printf("%s\n", ft_substr(str, 10, 6));
// }
// /*

// aksldlfjdkdlsldkfkfkfjfj.........

// */