/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:00:08 by yironmak          #+#    #+#             */
/*   Updated: 2021/10/12 12:00:09 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		ft_putchar_fd(s[i], fd);
}
