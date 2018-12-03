/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_typemod_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:23:17 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:23:20 by mtshisw          ###   ########.fr       */
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

intmax_t	d_i_type_mod(t_box *box, intmax_t storage)
{
	intmax_t cast;

	cast = 0;
	if (box->len_modifier == -1)
		cast = (int)storage;
	else if (box->len_modifier == 0)
		cast = (signed char)(storage);
	else if (box->len_modifier == 1)
		cast = (short)(storage);
	else if (box->len_modifier == 2)
		cast = (long long)(storage);
	else if (box->len_modifier == 3)
		cast = (long)(storage);
	else if (box->len_modifier == 4)
		cast = (intmax_t)(storage);
	else if (box->len_modifier == 5)
		cast = (ptrdiff_t)(storage);
	else if (box->len_modifier == 6)
		cast = (size_t)(storage);
	return (cast);
}

intmax_t	oux_type_mod(t_box *box, uintmax_t storage)
{
	uintmax_t cast;

	cast = 0;
	if (box->len_modifier == -1)
		cast = (unsigned int)storage;
	else if (box->len_modifier == 0)
		cast = (unsigned char)(storage);
	else if (box->len_modifier == 1)
		cast = (unsigned short)(storage);
	else if (box->len_modifier == 2)
		cast = (unsigned long long)(storage);
	else if (box->len_modifier == 3)
		cast = (unsigned long)(storage);
	else if (box->len_modifier == 4)
		cast = (uintmax_t)(storage);
	else if (box->len_modifier == 5)
		cast = (ptrdiff_t)(storage);
	else if (box->len_modifier == 6)
		cast = (size_t)(storage);
	return (cast);
}
