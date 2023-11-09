/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 01:28:59 by fda-estr          #+#    #+#             */
/*   Updated: 2023/04/16 19:59:16 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*copy;

	copy = s;
	while (n--)
		*copy++ = '\0';
}

// int	main()
// {
// 	char s[] = "Pidaras";
// 	ft_bzero(s, 4);
// 	printf("%s\n", s);
// }