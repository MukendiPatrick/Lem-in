/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:21:42 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:21:46 by mtshisw          ###   ########.fr       */
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

char		*percent_printer(char *value, t_box *box)
{
	value = field_width_handler(box, value);
	precision_handler(box, &value);
	if (value == NULL)
	{
		value = ft_strnew(1);
		value[0] = '%';
	}
	else
		value[ft_strlen(value) - 1] = '%';
	value = flag_handler(box, value, 1);
	return (value);
}

void		specifier_update(t_box *box)
{
	if (box->specifier == 'D' || box->specifier == 'O' || box->specifier == 'U'
			|| box->specifier == 'C' || box->specifier == 'S')
	{
		box->len_modifier = 3;
		if (box->specifier != 'S' && box->specifier != 'C')
			box->specifier = ft_tolower(box->specifier);
	}
	if (box->specifier == 'p')
	{
		box->pound_flag = 1;
		box->len_modifier = 3;
	}
}

static int	null_check_and_print(char **value, int *print_len, t_box *box)
{
	int i;

	i = 0;
	if (*value == NULL && box->specifier == 'S')
	{
		*print_len = -1;
		ft_putstr("(null)");
	}
	else if (*value == NULL)
	{
		ft_putstr("(null)");
		*print_len += 6;
	}
	else
	{
		ft_putstr(*value);
		*print_len += ft_strlen(*value);
		free(*value);
	}
	return (*print_len);
}

int			print_spec(t_box *box, va_list *param_list)
{
	char	c;
	char	*value;
	int		print_len;

	print_len = 0;
	value = NULL;
	specifier_update(box);
	c = box->specifier;
	if (box->specifier == '%')
		value = percent_printer(value, box);
	else if (c == 'd' || c == 'i')
		value = d_i_printer(value, box, param_list);
	else if (c == 'o')
		value = o_printer(value, box, param_list);
	else if (c == 'x' || c == 'X')
		value = x_printer(value, box, param_list);
	else if (c == 's' || c == 'S')
		value = str_printer(box, param_list, value);
	else if (c == 'c' || c == 'C')
		value = c_printer(box, param_list, value, &print_len);
	else if (c == 'u' || c == 'U')
		value = u_printer(box, param_list, value);
	else if (c == 'p')
		value = p_printer(value, box, param_list);
	return (null_check_and_print(&value, &print_len, box));
}

int			move_past_specifier(const char **format, t_box *box, int *len_value)
{
	if (**format != '%')
	{
		ft_putchar(**format);
		*len_value += 1;
		*format += 1;
		return (0);
	}
	*format += 1;
	flags_match(format, box);
	field_width(format, box);
	precision(format, box);
	length_modifier(format, box);
	if ((matches_any_char(g_specifier, **format)))
	{
		box->specifier = **format;
		*format += 1;
	}
	return (1);
}
