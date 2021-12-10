/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:00:02 by yironmak          #+#    #+#             */
/*   Updated: 2021/10/12 12:00:02 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*temp1;
	char	*temp2;

	if (dst == src)
		return (dst);
	i = -1;
	if (dst < src)
	{
		temp1 = (char *) dst;
		temp2 = (char *) src;
		while (len--)
			*temp1++ = *temp2++;
	}
	else
	{
		temp1 = (char *) dst + (len - 1);
		temp2 = (char *) src + (len - 1);
		while (len--)
			*temp1-- = *temp2--;
	}
	return (dst);
}
