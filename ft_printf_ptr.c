/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:30:37 by darkwater         #+#    #+#             */
/*   Updated: 2023/11/04 01:30:32 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	prn_ptr_hex(unsigned long num)
{
	size_t	count;
	char	*hex_digits;

	count = 0;
	hex_digits = "0123456789abcdef";
	if (num >= 16)
		count += prn_ptr_hex(num / 16);
	return (count += ft_printf_char(hex_digits[num % 16]));
}

int	ft_printf_ptr(void *ptr)
{
	size_t	count;

	count = 2;
	write(1, "0x", 2);
	count += prn_ptr_hex((unsigned long)ptr);
	return (count);
}
