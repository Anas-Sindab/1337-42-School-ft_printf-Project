/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:17:58 by anasinda          #+#    #+#             */
/*   Updated: 2025/12/27 05:48:15 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static void	ft_check_specifier(const char *format_str, int *count, va_list args)
{
	if (*format_str == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (*format_str == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (*format_str == 'p')
		ft_ptr_check(va_arg(args, void *), count);
	else if (*format_str == 'd' || *format_str == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (*format_str == 'u')
		ft_putsigned(va_arg(args, unsigned int), count);
	else if (*format_str == 'x' || *format_str == 'X')
		ft_puthex(va_arg(args, unsigned int), *format_str, count);
	else if (*format_str == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *format_str, ...)
{
	int		count;
	va_list	args;

	va_start(args, format_str);
	count = 0;
	if (*format_str == '\0')
		count = 1;
	while (*format_str)
	{
		if (*format_str == '%')
			ft_check_specifier(++format_str, &count, args);
		else
			ft_putchar(*format_str, &count);
		format_str++;
	}
	va_end(args);
	return (count);
}
