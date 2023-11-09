/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:12:33 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/15 20:57:45 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_check(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;
	char	*dest;

	str = (char *) s1;
	if (!str)
		return (NULL);
	while (*str)
	{
		if (char_check(*str, set) == 0)
			break ;
		str++;
	}
	len = ft_strlen(str);
	while (len != 0)
	{
		if (char_check(str[len - 1], set) == 0)
			break ;
		len--;
	}
	dest = ft_substr(str, 0, len);
	return (dest);
}
