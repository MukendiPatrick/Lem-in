/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:04:07 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:04:10 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_make_word(char *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while ((s[i] != c) && (s[i] != '\0'))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while ((s[i] != c) && (s[i] != '\0'))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
