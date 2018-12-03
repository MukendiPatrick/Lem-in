/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_sub_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:21:11 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:21:15 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_start_strstr(const char *big, const char *little)
{
	size_t	j;
	char	*ptr;

	j = 0;
	ptr = (char *)big;
	if (!(little[j]) && !(ptr[j]))
		return (ptr);
	while ((ptr[j] == little[j]) && ptr[j])
	{
		j++;
	}
	if (!little[j])
		return (&ptr[j]);
	return (NULL);
}

int		matches_any_char(const char *string, char char_to_match)
{
	while (*string)
	{
		if (char_to_match == *string)
			return (1);
		string++;
	}
	return (0);
}

int		matches_any_array(const char **str, const char *to_match, t_box *box)
{
	int i;

	i = 0;
	while (*str)
	{
		if (ft_start_strstr(to_match, *str))
		{
			box->len_modifier = i;
			return (ft_strlen(*str));
		}
		i++;
		str += 1;
	}
	return (0);
}
