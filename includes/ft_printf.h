/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:15:44 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/11/28 00:55:28 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ************* */
/* Packages Used */
/* ************* */

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

/* ************** */
/* Functions Used */
/* ************** */

int		ft_handleinput(char format, va_list *args);
int		ft_parseinput(va_list *args, const char *s);
int		ft_printf(const char *s, ...);

#endif