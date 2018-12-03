/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:35:33 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/17 17:39:44 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		navigate_right(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[y][lem->rooms - 1] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		navigate_right(lem, lst, y, x + 1);
		lst = add_room(lem, lst, x);
		navigate_up(lem, lst, y - 1, x);
		navigate_down(lem, lst, y + 1, x);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		navigate_right(lem, lst, y, x + 1);
	return (0);
}

int		navigate_left(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[y][lem->rooms - 1] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		navigate_left(lem, lst, y, x - 1);
		lst = add_room(lem, lst, x);
		navigate_up(lem, lst, y - 1, x);
		navigate_down(lem, lst, y + 1, x);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		navigate_left(lem, lst, y, x - 1);
	return (0);
}

int		navigate_up(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[lem->rooms - 1][x] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		navigate_up(lem, lst, y - 1, x);
		lst = add_room(lem, lst, y);
		navigate_left(lem, lst, y, x - 1);
		navigate_right(lem, lst, y, x + 1);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		navigate_up(lem, lst, y - 1, x);
	return (0);
}

int		navigate_down(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[lem->rooms - 1][x] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		navigate_down(lem, lst, y + 1, x);
		lst = add_room(lem, lst, y);
		navigate_left(lem, lst, y, x - 1);
		navigate_right(lem, lst, y, x + 1);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		navigate_down(lem, lst, y + 1, x);
	return (0);
}

void	navigate(t_lem_in *lem)
{
	char *tmp;

	tmp = ft_strdup(lem->rm[0].name);
	navigate_right(lem, tmp, 0, 0);
	free(tmp);
}
