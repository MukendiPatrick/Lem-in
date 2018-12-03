/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_motion_prt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:31:57 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/17 17:35:50 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_ants(t_lem_in *lem, int ant, int rm)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(lem->rm[lem->rmf[rm]].name);
	if (ft_strcmp(lem->rm[lem->rmf[rm]].name, lem->rm[lem->end].name)
		&& (ant != lem->ants))
		ft_putchar(' ');
	if (ft_strequ(lem->rm[lem->rmf[rm]].name, lem->rm[lem->end].name)
		&& (ant != lem->ants))
		ft_putchar(' ');
}

void	ants_motion_2(t_lem_in *lem, int ant, int rm, int count)
{
	lem->rm[lem->rmf[rm - 1]].ants_num--;
	lem->rm[lem->rmf[rm]].ants_num++;
	if (rm == lem->len - 1)
	{
		print_ants(lem, ant + (count - ant), rm);
		move_rec(lem, ant + (count - ant) + 1, rm - 1, count + 1);
	}
	else
	{
		print_ants(lem, ant, rm);
		move_rec(lem, ant + 1, rm - 1, count);
	}
}

int		move_rec(t_lem_in *lem, int ant, int rm, int count)
{
	if (lem->rm[lem->rmf[lem->len - 1]].ants_num == lem->ants)
		return (1);
	if (rm <= 0)
	{
		ft_putchar('\n');
		move_rec(lem, 1, lem->len - 1, count);
		return (0);
	}
	else if (lem->rm[lem->rmf[rm - 1]].ants_num == 0
		&& lem->rm[lem->rmf[rm]].ants_num >= 1)
		return (0);
	else if (lem->rm[lem->rmf[rm - 1]].ants_num >= 1)
	{
		ants_motion_2(lem, ant, rm, count);
	}
	move_rec(lem, ant, rm - 1, count);
	return (0);
}

void	ants_motion(t_lem_in *lem)
{
	lem->rm[lem->rmf[0]].ants_num = lem->ants;
	move_rec(lem, 1, lem->len - 1, 1);
	ft_putchar('\n');
}

void	rooms_order(t_lem_in *lem)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	s = ft_strsplit(lem->lst, '-');
	while (*(s + i))
	{
		j = 0;
		while (j <= lem->rooms - 1)
		{
			if (ft_strequ(*(s + i), lem->rm[j].name))
				lem->rmf[i] = j;
			j++;
		}
		free(s[i]);
		i++;
	}
	free(s);
}
