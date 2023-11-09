/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_sizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:36:42 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/15 20:56:42 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Only workes with rectangular matrixes*/
/*d = the dimention [Height (h) width(w) area (a)]*/

int	matrix_sizer(char **mtx, char d)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (mtx[h])
		h++;
	w = ft_strlen(mtx[0]);
	if (d == 'h' || d == 'H')
		return (h);
	else if (d == 'w' || d == 'W')
		return (w);
	else if (d == 'a' || d == 'A')
		return (h * w);
	else
		return (0);
}
