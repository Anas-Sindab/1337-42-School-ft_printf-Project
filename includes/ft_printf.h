/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:19:35 by anasinda          #+#    #+#             */
/*   Updated: 2025/11/13 22:31:13 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format_str, ...);
void	ft_putstr(char *s, int *count);
void	ft_putsigned(unsigned int nbr, int *count);
void	ft_putptr(unsigned long ptn, int *count);
void	ft_putnbr(int n, int *count);
void	ft_puthex(unsigned int hex, char check, int *count);
void	ft_putchar(char c, int *count);
void	ft_ptr_check(void *ptr, int *count);

#endif