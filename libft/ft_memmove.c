/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:26:47 by fda-estr          #+#    #+#             */
/*   Updated: 2023/04/16 20:26:24 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (dest > src)
	{
		d += n - 1;
		s += n - 1;
		while (n != 0)
		{
			*d-- = *s--;
			n--;
		}
	}
	else if (dest < src)
	{
		while (n != 0)
		{
			*d++ = *s++;
			n--;
		}
	}
	return (dest);
}

// int main()
// {
// 	char str[] = "Francisco Miguel";
// 	char dest[] = "skdjmvcldmvmfkcockcn ";
// 	(char *) ft_memmove(dest, str, 9);
// 	printf("%s\n", dest);
// }