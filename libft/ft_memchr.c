/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:47:54 by fda-estr          #+#    #+#             */
/*   Updated: 2023/04/20 17:27:37 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Its not working

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	long unsigned int	i;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char) c)
			return ((char *) str + i);
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	char str[] = "Francisco Miguel da Estrela Inacio";
// 	printf("%s\n", (char *) ft_memchr(str, 'i', 50));
// }