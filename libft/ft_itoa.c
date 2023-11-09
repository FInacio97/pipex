/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:27:51 by fda-estr          #+#    #+#             */
/*   Updated: 2023/04/28 15:28:51 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_ver(long n)
{
	int	ver;

	ver = 0;
	if (n <= 0)
	{
		ver++;
		n *= -1;
	}
	while (n > 0)
	{
		ver++;
		n /= 10;
	}
	return (ver);
}

static void	ft_cont(unsigned char *str, long num, int ndig)
{
	while (num > 0)
	{
		str[ndig--] = (num % 10) + 48;
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	unsigned char	*str;
	int				ndig;
	long			num;

	num = n;
	ndig = digit_ver(num);
	str = malloc(sizeof(char) * (ndig + 1));
	if (!str)
		return (NULL);
	str[ndig--] = 0;
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	if (num == 0)
	{
		str[0] = '0';
	}
	else
		ft_cont(str, num, ndig);
	return ((char *) str);
}

// int main()
// {
// 	int i = 0;
// 	char *str = ft_itoa(-10);
// 	printf("%s\n", str);
// 	while (str[i])
// 	{
// 		printf("[%i]%c\n", i, str[i]);
// 		i++;
// 	}

// }
// int main()
// {
// 	printf("%d\n", digit_ver(10));
// }