/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 00:13:57 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/11/28 10:48:50 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (n / 10 > 0)
		count += ft_putunbr_fd(n / 10, fd);
	c = n % 10 + '0';
	count += write(fd, &c, 1);
	return (count);
}
