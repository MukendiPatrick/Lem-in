/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cpu_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:16:14 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:16:20 by mtshisw          ###   ########.fr       */
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

char	*char_field_width_handler(t_box *box, char *value)
{
	int		i;
	int		j;
	char	*giver;
	int		min;

	i = ((value == NULL) ? 0 : ft_strlen(value));
	if (i == 0)
		i++;
	j = 0;
	min = box->field_width;
	if ((i = (min - i)) > 0)
	{
		giver = (char *)ft_memalloc(1 + min);
		while (j < i)
		{
			giver[j] = ' ';
			j++;
		}
		giver[j] = '\0';
		ft_strcat(giver, value);
		return (giver);
	}
	return (value);
}

char	*c_printer(t_box *box, va_list *param_list, char *v, int *l)
{
	v = ft_strnew(1);
	if (box->specifier == 'C' || box->len_modifier == 'l')
	{
		v[0] = (char)(wint_t)va_arg(*param_list, wint_t);
		if (v[0] == '\0')
			*l += 1;
		v = char_field_width_handler(box, v);
		if (box->minus_flag > 0)
			left_align_str(v);
	}
	else if (box->specifier == 'c')
	{
		v[0] = va_arg(*param_list, int);
		if (v[0] == 0)
		{
			ft_putchar('\0');
			*l += 1;
		}
		v = char_field_width_handler(box, v);
		if (box->minus_flag > 0)
			left_align_str(v);
	}
	return (v);
}

char	*u_printer(t_box *box, va_list *param_list, char *value)
{
	uintmax_t	ustorage;

	ustorage = oux_type_mod(box, (va_arg(*param_list, uintmax_t)));
	value = pf_ubig_itoa_base(ustorage, 10);
	value = o_precision_handler(box, &value);
	value = str_field_width_handler(box, value);
	if (box->minus_flag > 0)
		left_align_str(value);
	if (box->zero_flag > 0)
		zero_flag_handler(value);
	return (value);
}

char	*p_printer(char *value, t_box *box, va_list *param_list)
{
	uintmax_t	ustorage;

	ustorage = oux_type_mod(box, (va_arg(*param_list, uintmax_t)));
	value = pf_ubig_itoa_base(ustorage, 16);
	if (box->pound_flag > 0)
		value = ft_strstick("0x", value, 0);
	value = field_width_handler(box, value);
	precision_handler(box, &value);
	value = ox_flag_handler(box, value);
	if (box->specifier == 'X')
		str_toupper(value);
	return (value);
}
