/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_meta_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:18:55 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:19:01 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <wchar.h>

char	*ft_strstick(char *prepend, char *original, int index)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = index;
	new = ft_strnew(ft_strlen(original + index) + ft_strlen(prepend));
	while (prepend[i])
	{
		new[i] = prepend[i];
		i++;
	}
	while (original[j])
	{
		new[i] = original[j];
		j++;
		i++;
	}
	ft_strdel(&original);
	return (new);
}

int		digit_counter(char *str)
{
	int i;
	int num_digits;

	i = 0;
	num_digits = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			num_digits++;
		i++;
	}
	return (num_digits);
}

void	left_align_number(char *value)
{
	int count;
	int str_len;
	int i;

	i = 0;
	count = 0;
	str_len = ft_strlen(value);
	while (value[count] == '0' || value[count] == ' ')
		count++;
	while (value[count])
	{
		value[i] = value[count];
		count++;
		i++;
	}
	while (value[i])
	{
		value[i] = ' ';
		i++;
	}
}

void	zero_flag_handler(char *value)
{
	int i;

	i = 0;
	while (value[i] == ' ')
	{
		value[i] = '0';
		i++;
	}
}

void	str_toupper(char *value)
{
	while (*value)
	{
		*value = ft_toupper(*value);
		value++;
	}
}
