/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 01:07:15 by fda-estr          #+#    #+#             */
/*   Updated: 2023/03/22 18:52:27 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*cp;

	cp = s;
	while (n--)
		*cp++ = (unsigned int) c;
	return (s);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	char str[] = "Francisco Miguel da Estela Inacio";
// 	printf("%s\n", str);
// 	ft_memset(str, 'c', sizeof(char) * 15);
// 	printf("%s\n", str);
// }