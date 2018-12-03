/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:46:49 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/17 17:48:25 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct	s_room
{
	char	*name;
	int		x;
	int		y;
	int		ants_num;
}				t_room;

typedef struct	s_lem_data
{
	char	**data;
	int		ants;
	t_room	*rm;
	char	**links;
	int		**map;
	int		rooms;
	int		link;
	int		start;
	int		end;
	char	*lst;
	int		len;
	int		*rmf;
}				t_lem_in;

t_lem_in		*initialize(void);
void			ft_print_links(t_lem_in *lem);
void			ft_convert_links(t_lem_in *lem);
void			ft_check_match(t_lem_in *lem, char **str, int i, int j);

int				read_info(t_lem_in *lem);
int				store_info(t_lem_in *lem);
void			order_rooms(t_lem_in *lem);
void			store_room(t_lem_in *lem, char *str);
void			store_ants(t_lem_in *lem, char *str);

int				ft_same_room(char *node, char *list);
int				get_list_len(t_lem_in *lem);
char			*add_room(t_lem_in *lem, char *lst, int rm);
int				navigate_count(char *lst);

void			navigate(t_lem_in *lem);
int				navigate_down (t_lem_in *lem, char *lst, int y, int x);
int				navigate_up (t_lem_in *lem, char *lst, int y, int x);
int				navigate_left (t_lem_in *lem, char *lst, int y, int x);
int				navigate_right (t_lem_in *lem, char *lst, int y, int x);

void			rooms_order(t_lem_in *lem);
void			ants_motion(t_lem_in *lem);
void			print_ants(t_lem_in *lem, int ant, int rm);
int				move_rec(t_lem_in *lem, int ant, int rm, int count);

int				error_detection(t_lem_in *lem);
#endif
