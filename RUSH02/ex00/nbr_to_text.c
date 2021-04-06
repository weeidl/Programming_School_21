/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_to_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:11:28 by dwren             #+#    #+#             */
/*   Updated: 2021/02/21 19:56:44 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void	nbr_out(char *s)
{
	while (*s)
		write(1, s++, 1);
	write(1, " ", 1);
}

char	*search(char *nbr, t_dict *dict)
{
	while (dict)
	{
		if (!compare_str(nbr, dict->nbr))
			return (dict->text);
        
        
		dict = dict->next;
	}
	return (0);
}

void	poryadok(t_dict *dict, int num)
{
	char	*tmp;
	char	*s;
	int		i;

    
	tmp = (char*)malloc(sizeof(char) * num + 2);
	i = 0;
	tmp[0] = '1';
	while (i < num)
	{
		tmp[i * 3 + 1] = '0';
		tmp[i * 3 + 2] = '0';
		tmp[i * 3 + 3] = '0';
		tmp[i * 3 + 4] = '\0';
		i++;
	}
	s = search(tmp, dict);
	nbr_out(s);
	free(tmp);
}

int		begin(char *nbr, t_dict *dict, int size)
{
	int		i;
	int		sdvig;

	i = size % 3;
	sdvig = 0;
	if (i == 2)
	{
		sdvig += 2;
		if (nbr[0] == '1')
			if01n(nbr, dict, 0);
		else
			if0nn(nbr, dict, 0);
	}
	else if (i == 1)
	{
		sdvig++;
		if00n(nbr, dict, 0);
	}
	if (size > 3 && i != 0)
		poryadok(dict, size / 3);
	return (sdvig);
}

void	nbr_to_text(char *nbr, t_dict *dict)
{
	int		size;
	int		i;

	size = 0;
	if (!if000(nbr, dict))
		return ;
	while (nbr[size])
		size++;
	i = begin(nbr, dict, size);
	while (i < size)
	{
		if (nbr[i] != '0')
			ifn00(nbr, dict, i);
		if (nbr[i + 1] == '1')
			if01n(nbr, dict, i + 1);
		else if (nbr[i + 1] != '0')
			if0nn(nbr, dict, i + 1);
		else if (nbr[i + 2] != '0')
			if00n(nbr, dict, i + 2);
		if ((size - i) / 3 - 1 > 0
				&& !(nbr[i] == '0' && nbr[i + 1] == '0' && nbr[i + 2] == '0'))
			poryadok(dict, (size - i) / 3 - 1);
		i += 3;
	}
	write(1, "\n", 1);
}
