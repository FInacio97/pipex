/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 07:02:15 by fda-estr          #+#    #+#             */
/*   Updated: 2023/04/20 20:38:24 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

// meter o ft_strlen quando o make file estiver a funcionar como deve ed ser

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;
	char	*l;

	b = (char *) big;
	l = (char *) little;
	if (!*little)
		return ((char *) big);
	i = 0;
	while (b[i] && i < len)
	{
		j = 0;
		while (l[j] == b[i + j] && i + j < len)
		{
			if (l[j + 1] == 0)
				return ((char *) big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	char lt[] = "Miguel";
// 	char big[] = "Francisco Miguel da Estrela Inacio";
// 	char *res = ft_strnstr(big, lt, 15);
// 	if (res == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", res);
// }