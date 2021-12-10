/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:59:41 by yironmak          #+#    #+#             */
/*   Updated: 2021/10/12 11:59:41 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	num_len(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	if (n == -2147483648)
		return (ft_strjoin("-", "2147483648"));
	res = malloc(num_len(n) + 1);
	if (res == NULL)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	i = num_len(n);
	res[i] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		res[--i] = (n % 10) + 48;
		n /= 10;
	}
	return (res);
}
