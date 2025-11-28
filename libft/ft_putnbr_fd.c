/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:55:18 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/11/28 10:46:43 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		count += write(fd, "-", 1);
		count += ft_putnbr_fd(-n, fd);
		return (count);
	}
	else
	{
		if (n / 10 > 0)
			count += ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
		count += write(fd, &c, 1);
		return (count);
	}
}
