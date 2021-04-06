/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:40:13 by dwren             #+#    #+#             */
/*   Updated: 2021/02/21 22:09:12 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char	*work(int argc, char **argv, char **dict_name)
{
	char	*str;
	char	buf[1000];
	int		hmuch;

	if (argc > 3)
		return (0);
	if (argc == 1)
	{
		write(1, "Enter your number: ", 19);
		if ((hmuch = read(1, buf, 1000)) <= 1)
			return (0);
		str = (char*)malloc(sizeof(char) * hmuch);
		str[hmuch - 1] = '\0';
		while (hmuch > 1)
		{
			str[hmuch - 2] = buf[hmuch - 2];
			hmuch--;
		}
	}
	else
		str = (argc == 3) ? argv[2] : argv[1];
	*dict_name = (argc == 3) ? argv[1] : "numbers.dict";
	str = check_nbr(str);
	return (str);
}

void	ch_val(t_dict **i, t_dict **j)
{
	char	*tmp;

	tmp = (*i)->nbr;
	(*i)->nbr = (*j)->nbr;
	(*j)->nbr = tmp;
	tmp = (*i)->text;
	(*i)->text = (*j)->text;
	(*j)->text = tmp;
}

int		if_every_key2(t_dict *dict)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * 38);
	i = 3;
	while (i <= 36)
	{
		tmp[0] = '1';
		j = 1;
		while (j <= i)
		{
			tmp[j] = '0';
			j++;
		}
		tmp[j] = '\0';
		if (!seek(dict, tmp))
			return (0);
		i += 3;
	}
	free(tmp);
	return (1);
}
