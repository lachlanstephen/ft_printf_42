/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:13:21 by darkwater         #+#    #+#             */
/*   Updated: 2023/11/03 08:56:00 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(int num)
{
	size_t	count;
	char	*str;

	str = ft_itoa(num);
	count = ft_printf_str(str);
	free(str);
	return (count);
}
