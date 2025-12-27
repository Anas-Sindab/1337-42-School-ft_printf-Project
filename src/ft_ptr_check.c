/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:56:11 by anasinda          #+#    #+#             */
/*   Updated: 2025/12/27 05:48:45 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_ptr_check(void *ptr, int *count)
{
	unsigned long	ptn;

	if (!ptr)
		*count += write(1, "(nil)", 5);
	else
	{
		ptn = (unsigned long)ptr;
		ft_putstr("0x", count);
		ft_putptr(ptn, count);
	}
}
