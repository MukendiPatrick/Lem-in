/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:09:30 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:09:33 by mtshisw          ###   ########.fr       */
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

int	ft_printf(const char *format, ...)
{
	int		len_value;
	va_list	param_list;
	t_box	*box;

	va_start(param_list, format);
	if (!(box = box_initialize()))
		return (0);
	len_value = 0;
	while (*format != '\0')
	{
		if (move_past_specifier(&format, box, &len_value))
		{
			len_value += print_spec(box, &param_list);
		}
	}
	free(box);
	va_end(param_list);
	return (len_value);
}
