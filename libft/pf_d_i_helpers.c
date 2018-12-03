/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d_i_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:16:51 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:16:54 by mtshisw          ###   ########.fr       */
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

char	*d_i_precision_handler(t_box *box, char **value, intmax_t storage)
{
	int		num_digits;
	int		str_len;
	char	*new;
	char	*ret;

	new = NULL;
	if (*value == NULL)
		return (*value);
	num_digits = digit_counter(*value);
	str_len = ft_strlen(*value);
	if (box->precision == 0 && storage == 0)
	{
		new = ft_strnew(0);
		ft_strdel(value);
		return (new);
	}
	if (box->precision > num_digits)
	{
		new = ft_strnew(box->precision - num_digits);
		ft_memset(new, '0', (box->precision - num_digits));
		ret = ft_strstick(new, *value, 0);
		ft_strdel(&new);
		return (ret);
	}
	return (*value);
}

char	*d_i_flag_handler(t_box *box, char *value, intmax_t storage)
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
			value = ft_strstick("+", value, i);
	}
	else if (box->space_flag > 0 && ft_isdigit(*value))
		value = ft_strstick(" ", value, 0);
	return (value);
}

char	*d_i_space_plus_handler(t_box *box, char *value, intmax_t storage)
{
	int i;

	i = 0;
	if (box->space_flag > 0 && storage != 0)
	{
		if (*value == '0' && digit_count(value) > box->precision)
			*value = ' ';
		if (*value != ' ' && *value != '-')
			value = ft_strstick(" ", value, 0);
	}
	if (box->plus_flag > 0 && storage >= 0)
	{
		if ((*value == '0' && digit_count(value) > box->precision &&
					storage != 0))
			*value = '+';
		else if (*value == ' ')
		{
			while (value[i] == ' ')
				i++;
			value[i - 1] = '+';
		}
		else
			value = ft_strstick("+", value, 0);
	}
	return (value);
}

void	d_i_zero_flag_handler(t_box *box, char *value)
{
	int i;

	if (box->precision > -1)
		return ;
	i = 0;
	while (value[i] == ' ')
	{
		value[i] = '0';
		i++;
	}
}

char	*d_i_printer(char *value, t_box *box, va_list *param_list)
{
	intmax_t	storage;

	storage = d_i_type_mod(box, (va_arg(*param_list, intmax_t)));
	if (storage < 0)
		value = pf_ubig_itoa_base(absolute_value(storage), 10);
	else
		value = pf_big_itoa_base(storage, 10);
	if (storage < 0 && (ft_strchr(value, '-') == NULL))
		value = ft_strstick("-", value, 0);
	value = d_i_precision_handler(box, &value, storage);
	value = str_field_width_handler(box, value);
	if (box->minus_flag > 0)
		left_align_str(value);
	else if (box->zero_flag > 0)
		d_i_zero_flag_handler(box, value);
	value = d_i_negative_handler(value, storage);
	value = d_i_space_plus_handler(box, value, storage);
	if (value[box->field_width] == ' ')
		value[box->field_width] = '\0';
	return (value);
}
