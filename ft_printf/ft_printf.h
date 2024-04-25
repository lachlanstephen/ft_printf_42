/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:22:31 by lstephen          #+#    #+#             */
/*   Updated: 2024/04/21 02:56:04 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				ft_printf_char(int c);
int				ft_printf_str(char *str);
int				ft_printf_int(int num);
int				ft_printf_ptr(void *ptr);
int				ft_printf_unsigned(unsigned int num);
int				ft_printf_hex(unsigned int num, char type);

#endif
