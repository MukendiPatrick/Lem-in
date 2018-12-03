/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:33:31 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/17 17:38:42 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_same_room(char *node, char *list)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	s = ft_strsplit(list, '-');
	while (*(s + i))
	{
		if (ft_strequ(node, s[i]))
		{
			j = 0;
			while (*(s + i + j))
				free(s[i + j++]);
			free(s);
			return (1);
		}
		free(s[i++]);
	}
	free(s);
	return (0);
}

char	*add_room(t_lem_in *lem, char *lst, int rm)
{
	char *s;

	if (!ft_same_room(lem->rm[rm].name, lst))
	{
		s = ft_strjoin(lst, "-");
		lst = ft_strjoin(s, lem->rm[rm].name);
		free(s);
		if (rm == lem->rooms - 1)
		{
			if (navigate_count(lst) < lem->len)
			{
				lem->len = navigate_count(lst);
				free(lem->lst);
				lem->lst = ft_strdup(lst);
			}
		}
	}
	return (lst);
}

int		navigate_count(char *lst)
{
	char	**str;
	int		len;

	str = ft_strsplit(lst, '-');
	len = 0;
	while (*(str + len))
		free(str[len++]);
	free(str);
	return (len);
}
