/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_meta_helpers1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:19:14 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:19:19 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <wchar.h>

char		*pf_strnewchar(size_t size, char any)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	while (i < size)
	{
		str[i] = any;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void		left_align_str(char *value)
{
	int count;
	int str_len;
	int i;

	i = 0;
	count = 0;
	str_len = ft_strlen(value);
	while (value[count] == ' ')
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

int			digit_count(char *value)
{
	int count;

	count = 0;
	while (*value)
	{
		if (ft_isdigit(*value))
			count++;
		value++;
	}
	return (count);
}

uintmax_t	absolute_value(intmax_t storage)
{
	uintmax_t		ret;

	ret = -(storage);
	return (ret);
}
