/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:00:01 by yironmak          #+#    #+#             */
/*   Updated: 2021/10/12 12:00:01 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*temp1;
	char	*temp2;

	if (!dst && !src)
		return (NULL);
	i = -1;
	temp1 = (char *) dst;
	temp2 = (char *) src;
	while (n--)
		*temp1++ = *temp2++;
	return (dst);
}
