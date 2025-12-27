/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:02:44 by anasinda          #+#    #+#             */
/*   Updated: 2025/12/27 05:48:45 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putsigned(unsigned int nbr, int *count)
{
	char	c;

	if (nbr > 9)
		ft_putsigned(nbr / 10, count);
	c = (nbr % 10) + '0';
	*count += write(1, &c, 1);
}
