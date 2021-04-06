/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:26:21 by dwren             #+#    #+#             */
/*   Updated: 2021/02/21 22:09:06 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char	*back(char *s, int size, int i, int j)
{
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * size);
	j = 0;
	while (j < size)
	{
		tmp[j] = s[i + j];
		j++;
	}
	tmp[j] = '\0';
	if (s[i + j] != '\0')
		return (0);
	return (tmp);
}

char	*check_nbr(char *s)
{
	int		i;
	int		size;
	int		j;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	j = 0;
	while (s[i + j] == '0')
		j++;
	size = 0;
	i += j;
	while (s[i + size] >= '0' && s[i + size] <= '9')
		size++;
	if (j > 0 && size == 0 && s[i] == '\0')
		return ("0");
	if (size == 0)
		return (0);
	return (back(s, size, i, j));
}

int		seek(t_dict *dict, char *c1)
{
	t_dict	*runner;

	runner = dict;
	while (runner)
	{
		if (!compare_str(runner->nbr, c1))
			return (1);
		runner = runner->next;
	}
	return (0);
}

int		if_every_key(t_dict *dict)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * 4);
	while (i < 10)
	{
		tmp[0] = i + '0';
		tmp[1] = '\0';
		if (!seek(dict, tmp))
			return (0);
		tmp[0] = '1';
		tmp[1] = i + '0';
		tmp[2] = '\0';
		if (!seek(dict, tmp))
			return (0);
		tmp[0] = i + '0';
		tmp[1] = '0';
		tmp[2] = '\0';
		if (i >= 2 && !seek(dict, tmp))
			return (0);
		i++;
	}
	free(tmp);
	return (1);
}

int		if_100(t_dict *dict)
{
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * 38);
	tmp[0] = '1';
	tmp[1] = '0';
	tmp[2] = '0';
	tmp[3] = '\0';
	if (!seek(dict, tmp))
		return (0);
	free(tmp);
	return (1);
}
