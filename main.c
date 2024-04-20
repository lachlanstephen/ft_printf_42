/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:55:42 by lstephen          #+#    #+#             */
/*   Updated: 2024/04/21 03:05:30 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	character_tests(int *bytes_written, int *printf_bytes)
{
	ft_printf("\nCharacter Print Test\n\n");
	ft_printf("My function:\n");
	*bytes_written += ft_printf("%c %c %c", 'c', 's', 'p');
	ft_printf("\nPrintf Output:\n");
	*printf_bytes += printf("%c %c %c", 'c', 's', 'p');
	fflush(stdout);
}
	
void	string_tests(int *bytes_written, int *printf_bytes)
{
	ft_printf("\n\n\nString Print Test\n\n");
	ft_printf("My function:\n");
	*bytes_written += ft_printf("%s %s %s", "potato", "fried", "mashed");
	ft_printf("\nPrintf Output:\n");
	*printf_bytes += printf("%s %s %s", "potato", "fried", "mashed");
	fflush(stdout);
}

void	integer_tests(int *bytes_written, int *printf_bytes)
{
	ft_printf("\n\n\nInteger Print Test\n\n");
	ft_printf("My function:\n");
	*bytes_written += ft_printf("%d %i %d", 86123, -2147483647, 0);
	ft_printf("\nPrintf Output:\n");
	*printf_bytes += printf("%d %i %d", 86123, -2147483647, 0);
	fflush(stdout);
}

void	unsigned_tests(int *bytes_written, int *printf_bytes)
{
	ft_printf("\n\n\nUnsigned Int Print Test\n\n");
	ft_printf("My function:\n");
	*bytes_written += ft_printf("%u %u %u %u", 86123, -2147483647, 0, 2147483647);
	ft_printf("\nPrintf Output:\n");
	*printf_bytes += printf("%u %u %u %u", 86123, -2147483647, 0, 2147483647);
	fflush(stdout);
}

void	pointer_tests(int *bytes_written, int *printf_bytes)
{
	void	*testcase;

	testcase = malloc(sizeof(char) * 5);
	if (testcase == NULL)
	{
		free(testcase);
		return ;
	}
	ft_printf("\n\n\nPointer Print Test\n\n");
	ft_printf("My function:\n");
	*bytes_written += ft_printf("%p %p %p %p", (void *)bytes_written, (void *)printf_bytes, testcase, NULL);
	ft_printf("\nPrintf Output:\n");
	*printf_bytes += printf("%p %p %p %p", (void *)bytes_written, (void *)printf_bytes, testcase, NULL);
	fflush(stdout);
	free(testcase);
}

void	hex_lower_tests(int *bytes_written, int *printf_bytes)
{
	ft_printf("\n\n\nHex Lower Print Test\n\n");
	ft_printf("My function:\n");
	*bytes_written += ft_printf("%x %x %x %x", 86123, -2147483647, 0, 1406);
	ft_printf("\nPrintf Output:\n");
	*printf_bytes += printf("%x %x %x %x", 86123, -2147483647, 0, 1406);
	fflush(stdout);
}

void	hex_upper_tests(int *bytes_written, int *printf_bytes)
{
	ft_printf("\n\n\nHex Upper Print Test\n\n");
	ft_printf("My function:\n");
	*bytes_written += ft_printf("%X %X %X %X", 86123, -2147483647, 0, 1406);
	ft_printf("\nPrintf Output:\n");
	*printf_bytes += printf("%X %X %X %X", 86123, -2147483647, 0, 1406);
	fflush(stdout);
}

void	generic_tests(int *bytes_written, int *printf_bytes)
{
	void	*ptr;

	ptr = malloc(sizeof(void *) * 5);
	if (ptr == NULL)
	{
		free(ptr);
		return ;
	}	
	ft_printf("\n\n\nGeneric Print Test\n\n");
	ft_printf("My function:\n");
	*bytes_written += ft_printf("Char: %c, String: %s, Pointer: %p, Decimal: %d, Integer: %i, Unsigned: %u, Hex Lower: %x, Hex Upper: %X, Percent %%", 'L', "Hey There ;)", ptr, 257, 8392, -1239, 9278, 9278);
	ft_printf("\nPrintf Output:\n");
	*printf_bytes += printf("Char: %c, String: %s, Pointer: %p, Decimal: %d, Integer: %i, Unsigned: %u, Hex Lower: %x, Hex Upper: %X, Percent %%", 'L', "Hey There ;)", ptr, 257, 8392, -1239, 9278, 9278);
	fflush(stdout);
	free(ptr);
}

//FLAGS REQUIRED FOR BONUS:
// '-', '0', '.', '#', ' ', '+'
void	bonus_tests(int *bytes_written, int *printf_bytes)
{
	ft_printf("\n\t~ ~ ~ Bonus Flags Print Test ~ ~ ~\n");
	ft_printf("\nFlag: '-'\t(Testing: '%%-6...')\n");
	ft_printf("\nPrintf Output:\n");
	*printf_bytes += printf("%-6d %-6i %-6d", 86123, -2147483647, 0);
	printf("\n");
	*printf_bytes += printf("Char: %-6c, String: %-6s, Pointer: %-6p, Decimal: %-6d, Integer: %-6i, Unsigned: %-6u, Hex Lower: %-6x, Hex Upper: %-6X", 'L', "Hey There ;)", (void *)bytes_written, 257, 8392, -1239, 9278, 9278);
	fflush(stdout);
	ft_printf("\n\nFlag: '0'\t(Testing: '%%06...')\n");
	ft_printf("\nPrintf Output:\n");
	*printf_bytes += printf("%06d %06i %06d", 86123, -2147483647, 0);
	printf("\n");
	*printf_bytes += printf("Decimal: %06d, Integer: %06i, Unsigned: %06u, Hex Lower: %06x, Hex Upper: %06X", 257, 8392, -1239, 9278, 9278);
	fflush(stdout);
	ft_printf("\n\nFlag: '.'\t(Testing: '%%.6...')\n");
	ft_printf("\nPrintf Output:\n");
	*printf_bytes += printf("%.6d %.6i %.6d", 86123, -2147483647, 0);
	printf("\n");
	*printf_bytes += printf("String: %.6s, Decimal: %.6d, Integer: %.6i, Unsigned: %.6u, Hex Lower: %.6x, Hex Upper: %.6X", "Hey There ;)", 257, 8392, -1239, 9278, 9278);
	fflush(stdout);
	ft_printf("\n\nFlag: '#'\t(Testing: '%%#8...')\n");
	ft_printf("\nPrintf Output:\n");
	*printf_bytes += printf("%#8x %#8x %#8x %#8x", 86123, -2147483647, 0, 1406);
	printf("\n");
	*printf_bytes += printf("Hex Lower: %#8x, Hex Upper: %#8X", 9278, 9278);
	fflush(stdout);
	ft_printf("\n\nFlag: ' '\t(Testing: '%% 6...')\n");
	ft_printf("\nPrintf Output:\n");
	*printf_bytes += printf("% 6d % 6i % 6d", 86123, -2147483647, 0);
	printf("\n");
	*printf_bytes += printf("Decimal: % 6d, Integer: % 6i", 257, 8392);
	fflush(stdout);
	ft_printf("\n\nFlag: '+'\t(Testing: '%%+6...')\n");
	ft_printf("\nPrintf Output:\n");
	*printf_bytes += printf("%+6d %+6i %+6d", 86123, -2147483647, 0);
	printf("\n");
	*printf_bytes += printf("Decimal: %+6d, Integer: %+6i", 257, 8392);
	fflush(stdout);
}

int	main(void)
{
	int	bytes_written;
	int printf_bytes;

	bytes_written = 0;
	printf_bytes = 0;
/*	character_tests(&bytes_written, &printf_bytes);
	string_tests(&bytes_written, &printf_bytes);
	integer_tests(&bytes_written, &printf_bytes);
	unsigned_tests(&bytes_written, &printf_bytes);
	hex_lower_tests(&bytes_written, &printf_bytes);
	hex_upper_tests(&bytes_written, &printf_bytes);*/
	pointer_tests(&bytes_written, &printf_bytes);
	/*generic_tests(&bytes_written, &printf_bytes);
	bonus_tests(&bytes_written, &printf_bytes);*/
	printf("\n\nMy function bytes written: %d\n", bytes_written);
	printf("Inbuilt function bytes written: %d\n", printf_bytes);
	return (0);
}
