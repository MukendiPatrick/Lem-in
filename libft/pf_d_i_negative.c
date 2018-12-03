/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d_i_negative.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:17:13 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:17:18 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stddef.h>
#include <wchar.h>

char	*d_i_negative_handler(char *value, intmax_t storage)
{
	int i;

	i = 0;
	if (storage < 0 && *value != '-')
	{
		while (value[i])
		{
			if (value[i] == '-')
				value[i] = '0';
			i++;
		}
		i = 0;
		while (value[i] == ' ')
			i++;
		if (value[i] == '0' || value[i] == '-')
			value[i] = '-';
		else
			value[i - 1] = '-';
	}
	return (value);
}
