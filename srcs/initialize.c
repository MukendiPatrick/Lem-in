/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:33:49 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/17 17:39:29 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		initialize_2(t_lem_in *lem)
{
	int			i;

	lem->map = NULL;
	lem->rooms = 0;
	lem->link = 0;
	lem->start = 0;
	lem->end = 0;
	lem->len = 999;
	lem->rmf = (int *)malloc(sizeof(int) * 1000);
	i = 0;
	while (i < 1000)
		lem->rmf[i++] = -1;
	lem->lst = (char *)malloc(sizeof(char) * 1000);
	lem->lst = NULL;
}

t_lem_in	*initialize(void)
{
	t_lem_in	*lem;
	int			i;

	lem = (t_lem_in *)malloc(sizeof(t_lem_in));
	lem->data = (char **)malloc(sizeof(char *) * 3000);
	lem->ants = 0;
	lem->rm = (t_room *)malloc(sizeof(t_room) * 1000);
	i = 0;
	while (i < 1000)
	{
		lem->rm[i].name = NULL;
		lem->rm[i].x = 0;
		lem->rm[i].y = 0;
		lem->rm[i++].ants_num = 0;
	}
	lem->links = (char **)malloc(sizeof(char *) * 2000);
	i = 0;
	initialize_2(lem);
	return (lem);
}

void		ft_print_links(t_lem_in *lem)
{
	int		i;

	i = 0;
	while (lem->data[i])
	{
		ft_putstr(lem->data[i++]);
		ft_putchar('\n');
	}
}

void		ft_convert_links(t_lem_in *lem)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	lem->map = (int **)malloc(sizeof(int *) * lem->rooms);
	while (i < lem->rooms)
		lem->map[i++] = (int *)malloc(sizeof(int) * lem->rooms);
	while (k < lem->link)
	{
		str = ft_strsplit(lem->links[k++], '-');
		i = -1;
		while (++i < lem->rooms)
		{
			j = -1;
			while (++j < lem->rooms)
				ft_check_match(lem, str, i, j);
		}
		j = 0;
		while (*(str + j))
			free(str[j++]);
		free(str);
	}
}

void		ft_check_match(t_lem_in *lem, char **str, int i, int j)
{
	if ((ft_strequ(lem->rm[i].name, str[0]) &&
	ft_strequ(lem->rm[j].name, str[1])) || (ft_strequ(lem->rm[i].name, str[1])
	&& ft_strequ(lem->rm[j].name, str[0])))
	{
		lem->map[i][j] = 1;
		lem->map[j][i] = 1;
	}
}
