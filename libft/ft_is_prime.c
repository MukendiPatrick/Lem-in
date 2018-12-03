/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:01:27 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:01:39 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
	{
		return (0);
	}
	while ((i * i) <= nb)
	{
		if ((nb % i) == 0)
		{
			return (0);
		}
		i = i + 1;
	}
	return (1);
}