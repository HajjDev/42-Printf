/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:36:29 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/11/28 11:21:52 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_valid_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!(str[0]) || !(str[1]))
		return (0);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static char	*ft_reverse(char *reversed_nb, int i, char *to_print_nb)
{
	int	k;
	int	l;

	k = i - 1;
	l = 0;
	while (k >= 0)
	{
		to_print_nb[k] = reversed_nb[l];
		k--;
		l++;
	}
	to_print_nb[i] = '\0';
	return (to_print_nb);
}

static int	convert(unsigned int signed_nbr, int base_length, char *base)
{
	char			reversed_nb[32];
	char			to_print_nb[32];
	int				i;
	unsigned int	nbr;

	i = 0;
	nbr = signed_nbr;
	while (nbr > 0)
	{
		reversed_nb[i] = base[nbr % base_length];
		nbr /= base_length;
		i++;
	}
	reversed_nb[i] = '\0';
	ft_reverse(reversed_nb, i, to_print_nb);
	write(1, to_print_nb, i);
	return (i);
}

int	ft_putunbr_base(unsigned int nbr, char *base)
{
	int	valid_base;
	int	base_length;

	valid_base = ft_check_valid_base(base);
	if (valid_base)
	{
		if (nbr == 0)
			return (write(1, &base[0], 1));
		else
		{
			base_length = ft_strlen(base);
			return (convert(nbr, base_length, base));
		}
	}
	return (-1);
}
