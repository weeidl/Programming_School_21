/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeabuck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 04:28:33 by fmeabuck          #+#    #+#             */
/*   Updated: 2021/02/24 04:28:36 by fmeabuck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == 0)
		return (1);
	return (0);
}

int		nb_words(char *str, char *charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (is_sep(str[i + 1], charset) == 1 && is_sep(str[i], charset) == 0)
			words++;
		i++;
	}
	return (words);
}

void	word_in_tab(char *dest, char *from, char *charset)
{
	int	i;

	i = 0;
	while (is_sep(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = 0;
}

void	do_res(char **res, char *str, char *charset)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		if (is_sep(str[i], charset) == 1)
			i++;
		else
		{
			while (is_sep(str[i + j], charset) == 0)
				j++;
			res[k] = malloc(sizeof(char) * (j + 1));
			word_in_tab(res[k], str + i, charset);
			i += j;
			k++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		count;

	count = nb_words(str, charset);
	res = malloc(sizeof(char *) * (count + 1));
	res[count] = 0;
	do_res(res, str, charset);
	return (res);
}
