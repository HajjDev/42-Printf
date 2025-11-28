/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 00:00:14 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/11/28 00:57:04 by cel-hajj         ###   ########.fr       */
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
	if (format == 'c')
		ft_putchar_fd(va_arg(*args, int), 1);
	else if (format == 's')
		ft_putstr_fd(va_arg(*args, char *), 1);
	else if (format == 'd')
		ft_putnbr_fd(va_arg(*args, int), 1);
	else if (format == 'i')
		ft_putnbr_fd(va_arg(*args, int), 1);
	else if (format == 'u')
		ft_putunbr_fd(va_arg(*args, unsigned int), 1);
	else if (format == 'x')
		ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		ft_putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		ft_putchar_fd('%', 1);
	return (1);
}
