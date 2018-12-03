/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_big_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:22:12 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:22:18 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include <stdint.h>
#include "libft.h"

void	pf_put_big_nbr(intmax_t n)
{
	intmax_t	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		pf_put_big_nbr(nb / 10);
		pf_put_big_nbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}
