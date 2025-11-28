/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 00:00:14 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/11/28 11:20:41 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parseinput(va_list *args, const char *s)
{
	size_t	i;
	size_t	size;
	int		printed;

	i = 0;
	printed = 0;
	size = ft_strlen(s);
	while (i < size)
	{
		if (s[i] == '%' && s[i + 1])
		{
			printed += ft_handleinput(s[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			printed++;
		}
		i++;
	}
	return (printed);
}

int	ft_handleinput(char format, va_list *args)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (format == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1));
	else if (format == 's')
		return (ft_putstr_fd(va_arg(*args, char *), 1));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	else if (format == 'u')
		return (ft_putunbr_fd(va_arg(*args, unsigned int), 1));
	else if (format == 'x' || format == 'X')
	{
		if (format == 'X')
			hex = "0123456789ABCDEF";
		return (ft_putunbr_base(va_arg(*args, unsigned int), hex));
	}
	else if (format == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (format == '%')
		return (ft_putchar_fd('%', 1));
	return (-1);
}
