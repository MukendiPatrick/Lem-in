/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_meta_helpers3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:19:55 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:19:59 by mtshisw          ###   ########.fr       */
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

char	*field_width_handler(t_box *box, char *value)
{
	int		i;
	int		j;
	char	*giver;
	int		min;

	i = ((value == NULL) ? 0 : ft_strlen(value));
	j = 0;
	min = ((box->precision > box->field_width) ? box->precision :
			box->field_width);
	if ((i = (min - i)) > 0)
	{
		giver = (char *)ft_memalloc(1 + min);
		while (j < i)
		{
			giver[j] = ' ';
			j++;
		}
		giver[j] = '\0';
		if (value)
			ft_strcat(giver, value);
		ft_strdel(&value);
		return (giver);
	}
	return (value);
}

void	precision_handler(t_box *box, char **value)
{
	int		num_digits;
	int		str_len;
	int		minus_flag;

	if (*value == NULL)
		return ;
	minus_flag = 0;
	num_digits = digit_counter(*value);
	str_len = ft_strlen(*value);
	while ((box->precision - num_digits) > 0)
	{
		if ((*value)[str_len - num_digits - 1] == '-')
			minus_flag = 1;
		(*value)[str_len - num_digits - 1] = '0';
		num_digits++;
	}
	if (**value == '0' && minus_flag > 0)
		*value = ft_strstick("-", *value, 0);
	else if (minus_flag)
	{
		while (!(ft_isdigit(**value)))
			*value += 1;
		**value = '-';
	}
}

char	*flag_handler(t_box *box, char *value, intmax_t storage)
{
	int i;

	i = -1;
	if (box->minus_flag > 0)
		left_align_number(value);
	else if ((box->zero_flag) > 0)
		zero_flag_handler(value);
	if (storage == 0 && box->precision == 0)
		while (value[++i])
			value[i] = ' ';
	if (box->plus_flag > 0 && ft_isdigit(*value))
		value = ft_strstick("+", value, 0);
	else if (box->plus_flag > 0)
	{
		i = 0;
		while (value[i] == ' ')
			i++;
		if (!(value[i] == '-'))
			value[i - 1] = '+';
	}
	else if (box->space_flag > 0 && ft_isdigit(*value))
		value = ft_strstick(" ", value, 0);
	return (value);
}
