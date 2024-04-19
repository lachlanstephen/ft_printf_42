/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:34:43 by darkwater         #+#    #+#             */
/*   Updated: 2023/11/04 00:03:06 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsigned(unsigned int num)
{
	size_t	count;

	count = 0;
	if (num >= 10)
		count += ft_printf_unsigned(num / 10);
	return (count += ft_printf_char(num % 10 + '0'));
}
