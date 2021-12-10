/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:00:11 by yironmak          #+#    #+#             */
/*   Updated: 2021/10/12 12:00:12 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;

	copy = malloc(ft_strlen(s1) + 1);
	if (copy == NULL)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}
