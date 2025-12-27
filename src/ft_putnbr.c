/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:55:15 by anasinda          #+#    #+#             */
/*   Updated: 2025/12/27 05:48:45 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	long	num;
	char	c;

	num = (long)n;
	if (num < 0)
	{
		num = -num;
		*count += write(1, "-", 1);
	}
	if (num > 9)
		ft_putnbr(num / 10, count);
	c = (num % 10) + '0';
	*count += write(1, &c, 1);
}
