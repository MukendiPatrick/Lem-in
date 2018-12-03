/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:32:43 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/17 18:09:16 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	gen_order(t_lem_in *lem)
{
	read_info(lem);
	store_info(lem);
	if (error_detection(lem))
		exit(0);
	ft_convert_links(lem);
	navigate(lem);
	if (!lem->lst)
	{
		ft_putstr("Error : No valid solution\n");
		exit(0);
	}
	rooms_order(lem);
	ft_print_links(lem);
	ft_putchar('\n');
	ants_motion(lem);
}

void	free_memory(t_lem_in *lem)
{
	int i;

	i = 0;
	free(lem->data);
	free(lem->rm);
	while (lem->links[i])
	{
		free(lem->links[i]);
		lem->links[i] = NULL;
		i++;
	}
	free(lem->links);
	i = 0;
	while (i < lem->rooms)
	{
		free(lem->map[i]);
		lem->map[i] = NULL;
		i++;
	}
	free(lem->map);
	free(lem->lst);
	free(lem->rmf);
}

int		main(void)
{
	t_lem_in	*lem;

	lem = initialize();
	gen_order(lem);
	free_memory(lem);
	free(lem);
	return (0);
}
