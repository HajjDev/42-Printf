/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:54:15 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/11/28 10:29:28 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	length;
	size_t	i;

	if (s == NULL)
		return (ft_putstr_fd("(null)", 1));
	else
	{
		i = 0;
		length = ft_strlen(s);
		while (i < length)
		{
			write(fd, &s[i], 1);
			i++;
		}
		return (length);
	}
}
