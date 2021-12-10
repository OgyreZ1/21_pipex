/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:00:28 by yironmak          #+#    #+#             */
/*   Updated: 2021/10/12 13:41:44 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (len == 0 && ft_strlen(needle) != 0)
		return (NULL);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (len && *haystack)
	{
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0 && \
			len >= ft_strlen(needle))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
