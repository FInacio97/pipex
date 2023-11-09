/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_finder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:43:21 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/15 20:49:22 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	coordinate_finder(char **mtx, char c, char axle)
{
	int	i;
	int	j;

	i = 0;
	while (mtx[i])
	{
		j = 0;
		while (mtx[i][j] && mtx[i][j] != c)
			j++;
		if (mtx[i][j] == c)
			break ;
		i++;
	}
	if (axle == 'x')
		return (j);
	else if (axle == 'y')
		return (i);
	else
		return (-1);
}
