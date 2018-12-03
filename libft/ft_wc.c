/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:13:39 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:13:43 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

int	ft_wc(char *s, char c)
{
	int	i;
	int flag;
	int	words;

	i = 0;
	flag = 0;
	words = 0;
	while (s[i])
	{
		if ((s[i] != c) && flag == 0)
		{
			flag = 1;
			words += 1;
		}
		else if (s[i] == c)
		{
			flag = 0;
		}
		i++;
	}
	return (words);
}
