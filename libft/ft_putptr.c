/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:13:58 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/11/29 12:10:59 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *p)
{
	int				count;
	unsigned long	add;

	if (p == NULL)
		return (write(1, "(nil)", 5));
	add = (unsigned long) p;
	count = write(1, "0x", 2) + ft_putulnbr_base(add, "0123456789abcdef");
	return (count);
}
