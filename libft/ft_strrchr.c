/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 02:52:33 by fda-estr          #+#    #+#             */
/*   Updated: 2023/04/20 17:15:19 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (s[len] == (unsigned char) c)
		return ((char *) s + len);
	while (len != -1)
	{
		if (s[len] == (unsigned char) c)
			return ((char *) &s[len]);
		len--;
	}
	return (NULL);
}

// int main()
// {
//  	char *str = "Francisco Miguel da Estrela Inacio";
//  	char *dest = ft_strrchr(str, 'F');
//  	printf("%s\n", dest);
// }

/*// int main()
// {
// 	char str2[] = "";
// 	char *str = "Francisco Miguel da Estrela Inacio";
// 	char *dest = ft_strrchr(str, 'x');
	
// 	if (ft_strrchr(str2, '\0') == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", dest);
// }*/