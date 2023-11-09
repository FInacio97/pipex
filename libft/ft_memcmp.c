/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:53:44 by fda-estr          #+#    #+#             */
/*   Updated: 2023/04/16 20:25:29 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (str1 && (n-- - 1) != 0)
	{
		if (*str1 != *str2)
			break ;
		str1++;
		str2++;
	}
	c1 = *str1;
	c2 = *str2;
	return ((int) c1 - (int) c2);
}

// int main()
// {
// 	char str1[] = "zzzzzz";
// 	char str2[] = "abcdef";
// 	printf("%d\n", ft_memcmp(str1, str2, 20));
// }