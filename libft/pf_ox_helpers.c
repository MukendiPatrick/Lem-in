/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ox_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:20:19 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:20:27 by mtshisw          ###   ########.fr       */
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

char	*ox_flag_handler(t_box *box, char *value)
{
	char	*new;
	int		i;

	i = 0;
	new = value;
	if (box->minus_flag > 0 && box->pound_flag < 0)
		left_align_number(new);
	else if (box->minus_flag > 0)
		left_align_str(new);
	else if ((box->zero_flag) > 0)
		zero_flag_handler(new);
	if (box->pound_flag > 0)
	{
		if (new[1] != 'x' && new[0] == '0')
		{
			while (new[i] != 'x')
				i++;
			new[i] = '0';
			new[1] = 'x';
		}
	}
	return (new != NULL ? new : value);
}

char	*x_printer(char *value, t_box *box, va_list *param_list)
{
	uintmax_t	ustorage;

	ustorage = oux_type_mod(box, (va_arg(*param_list, uintmax_t)));
	if (ustorage != 0)
		value = pf_ubig_itoa_base(ustorage, 16);
	else if (ustorage == 0 && box->precision == 0 && box->field_width < 1)
		return (ft_strnew(0));
	else if (ustorage == 0 && box->precision == -1)
	{
		value = ft_getz(value);
		return (value);
	}
	else
		value = ft_strnew(0);
	if (box->pound_flag > 0 && ustorage != 0)
		value = ft_strstick("0x", value, 0);
	value = field_width_handler(box, value);
	precision_handler(box, &value);
	value = ox_flag_handler(box, value);
	if (box->specifier == 'X')
		str_toupper(value);
	return (value);
}

char	*o_precision_handler(t_box *box, char **value)
{
	int		str_len;
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	str_len = 0;
	if (*value == NULL)
		return (*value);
	else if (box->precision > (str_len = ft_strlen(*value)))
	{
		new = ft_strnew(box->precision - str_len);
		ft_memset((void *)new, '0', (box->precision - str_len));
		new = ft_strjoin(new, *value);
	}
	else
		return (*value);
	return (new);
}

char	*o_pound_handler(char *value, t_box *box, uintmax_t ustorage)
{
	int i;

	i = 0;
	if (box->pound_flag > 0 && value[i] == ' ')
	{
		while (value[i] == ' ')
			i++;
		value[i - 1] = '0';
		return (value);
	}
	else if (box->pound_flag > 0 && value[i] != ' ' &&
			(ustorage != 0 || box->precision > -1))
		return (ft_strjoin("0", value));
	return (value);
}

char	*o_printer(char *value, t_box *box, va_list *param_list)
{
	uintmax_t	ustorage;

	ustorage = oux_type_mod(box, (va_arg(*param_list, uintmax_t)));
	if (ustorage == 0 && box->precision == 0)
		value = ft_strnew(0);
	else if (ustorage == 0)
		value = ft_getz(value);
	else
		value = pf_ubig_itoa_base(ustorage, 8);
	value = o_precision_handler(box, &value);
	value = str_field_width_handler(box, value);
	value = o_pound_handler(value, box, ustorage);
	if (box->minus_flag > 0)
		left_align_str(value);
	if (box->zero_flag > 0)
		zero_flag_handler(value);
	return (value);
}
