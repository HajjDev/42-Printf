/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:53:01 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/11/29 12:25:50 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handleinput(char format, va_list *args)
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

static void	ft_handlep(size_t *i, int *printed, va_list *args, const char *s)
{
	int		result;
	size_t	size;

	size = ft_strlen(s);
	if ((*i) + 1 < size)
	{
		result = ft_handleinput(s[(*i) + 1], args);
		if (result == -1)
		{
			ft_putchar_fd('%', 1);
			ft_putchar_fd(s[(*i) + 1], 1);
			(*printed) += 2;
			(*i)++;
		}
		else
		{
			(*printed) += result;
			(*i)++;
		}
	}
	else
	{
		ft_putchar_fd('%', 1);
		(*printed)++;
	}
}

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
		if (s[i] == '%')
			ft_handlep(&i, &printed, args, s);
		else
		{
			ft_putchar_fd(s[i], 1);
			printed++;
		}
		i++;
	}
	return (printed);
}
