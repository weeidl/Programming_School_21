/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 00:42:48 by dwren             #+#    #+#             */
/*   Updated: 2021/02/21 18:54:34 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int		if000(char *nbr, t_dict *dict)
{
	char	*s;

	if (nbr[0] == '0')
	{
		s = search("0", dict);
		nbr_out(s);
		return (0);
	}
	return (1);
}

void	ifn00(char *nbr, t_dict *dict, int i)
{
	char	*s;
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * 2);
	tmp[0] = nbr[i];
	tmp[1] = '\0';
	s = search(tmp, dict);
	nbr_out(s);
	s = search("100", dict);
	nbr_out(s);
	free(tmp);
}

void	if01n(char *nbr, t_dict *dict, int i)
{
	char	*s;
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * 3);
	tmp[0] = nbr[i];
	tmp[1] = nbr[i + 1];
	tmp[2] = '\0';
	s = search(tmp, dict);
	nbr_out(s);
	free(tmp);
}

void	if00n(char *nbr, t_dict *dict, int i)
{
	char	*s;
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * 2);
	tmp[0] = nbr[i];
	tmp[1] = '\0';
	s = search(tmp, dict);
	nbr_out(s);
	free(tmp);
}

void	if0nn(char *nbr, t_dict *dict, int i)
{
	char	*s;
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * 3);
	tmp[0] = nbr[i];
	tmp[1] = '0';
	tmp[2] = '\0';
	s = search(tmp, dict);
	nbr_out(s);
	if (nbr[i + 1] != '0')
		if00n(nbr, dict, i + 1);
	free(tmp);
}
