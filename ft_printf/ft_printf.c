/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:55:55 by lstephen          #+#    #+#             */
/*   Updated: 2024/04/21 03:29:08 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	specifier_select(char type, va_list args)
{
	size_t	count;

	count = 0;
	if (type == 'c')
		count += ft_printf_char(va_arg(args, int));
	else if (type == 's')
		count += ft_printf_str(va_arg(args, char *));
	else if (type == 'p')
		count += ft_printf_ptr(va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		count += ft_printf_int(va_arg(args, int));
	else if (type == 'u')
		count += ft_printf_unsigned(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		count += ft_printf_hex(va_arg(args, int), type);
	else if (type == '%')
		count += ft_printf_char('%');
	else
	{
		write(1, "\n\nERROR: No valid type specified!\n", 34);
		exit(1);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
			count += specifier_select(str[++i], args);
		else
			count += ft_printf_char(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
