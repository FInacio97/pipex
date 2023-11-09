/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:37:31 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/15 20:47:44 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcount(char *str, char c)
{
	int	n;

	n = 0;
	while (*str)
	{
		if (*str == c)
		{
			str++;
			continue ;
		}
		n++;
		while (*str != c && *str)
			str++;
	}
	return (n);
}

static void	ft_strfill(char **split, char *str, char c)
{
	int	i;
	int	first_i;
	int	str_i;

	i = 0;
	str_i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			continue ;
		}
		first_i = i;
		while (str[i] != c && str[i])
			i++;
		split[str_i] = malloc(i - first_i + 1);
		ft_strlcpy(split[str_i], str + first_i, i - first_i + 1);
		str_i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**split;
	int		nstr;

	str = (char *) s;
	nstr = ft_strcount(str, c);
	split = malloc(sizeof(char *) * (nstr + 1));
	if (!split)
		return (NULL);
	split[nstr] = 0;
	ft_strfill(split, str, c);
	return (split);
}
