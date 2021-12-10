/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:00:31 by yironmak          #+#    #+#             */
/*   Updated: 2021/10/12 12:38:41 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		len = 0;
	if (ft_strlen(s + start) <= len)
		len = ft_strlen(s + start);
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
		if (i >= start && i < start + len)
			sub[j++] = s[i];
	sub[j] = '\0';
	return (sub);
}
