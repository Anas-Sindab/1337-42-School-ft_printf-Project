/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:55:00 by anasinda          #+#    #+#             */
/*   Updated: 2025/12/27 05:48:45 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putptr(unsigned long ptn, int *count)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789abcdef";
	if (ptn >= 16)
	{
		ft_putptr((ptn / 16), count);
	}
	ft_putchar(str[(ptn % 16)], count);
}
