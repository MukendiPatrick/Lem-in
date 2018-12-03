/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_big_itoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:15:14 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:15:29 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

static void	ft_make_nbr(char *blank_string, int len, intmax_t n, int base)
{
	int		i;
	char	*lookup;

	lookup = "0123456789abcdef";
	i = 0;
	if (n < 0)
	{
		blank_string[i] = '-';
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		len--;
		blank_string[len] = (lookup[(n % base)]);
		n = n / base;
	}
}

static int	get_size(intmax_t n, int base)
{
	int len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}

char		*pf_big_itoa_base(intmax_t n, int base)
{
	int			len;
	intmax_t	copy;
	char		*blank_string;

	len = get_size(n, base);
	blank_string = NULL;
	copy = n;
	if (n == 0)
		return (blank_string = ft_getz(blank_string));
	if (!(blank_string = ft_strnew(len + 1)))
		return (NULL);
	ft_make_nbr(blank_string, len, n, base);
	return (blank_string);
}
