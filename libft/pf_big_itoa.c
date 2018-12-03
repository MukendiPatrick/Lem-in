/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_big_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:15:53 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:15:56 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

static void	ft_make_nbr(char *blank_string, int len, intmax_t n)
{
	int i;

	i = 0;
	blank_string[len] = '\0';
	if (n < 0)
	{
		blank_string[i] = '-';
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		len--;
		blank_string[len] = ((n % 10) + '0');
		n = n / 10;
	}
}

char		*pf_big_itoa(intmax_t n)
{
	int			len;
	intmax_t	copy;
	char		*blank_string;

	len = 0;
	blank_string = NULL;
	copy = n;
	if (n == 0)
	{
		if ((blank_string = ft_getz(blank_string)))
			return (blank_string);
		else
			return (NULL);
	}
	if (copy < 0)
		len++;
	while (copy != 0)
	{
		len++;
		copy = copy / 10;
	}
	if (!(blank_string = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_make_nbr(blank_string, len, n);
	return (blank_string);
}
