/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_meta_helpers2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:19:34 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:19:40 by mtshisw          ###   ########.fr       */
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

char	*str_field_width_handler(t_box *box, char *value)
{
	int		i;
	int		j;
	char	*giver;
	int		min;

	i = ((value == NULL) ? 0 : ft_strlen(value));
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
		ft_strdel(&value);
		return (giver);
	}
	return (value);
}
