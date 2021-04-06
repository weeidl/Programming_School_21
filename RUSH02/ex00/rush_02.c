/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:43:42 by dwren             #+#    #+#             */
/*   Updated: 2021/02/21 22:25:15 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int		prov_dict(t_dict *dict)
{
	if (!eject_twins(&dict))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	if (!if_every_key(dict))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	if (!if_every_key2(dict))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}

void	cl_ean(t_dict *dict)
{
	t_dict	*tmp;

	while (dict)
	{
		tmp = dict;
		dict = dict->next;
		free(tmp);
	}
}

int		main(int argc, char **argv)
{
	char	*nbr;
	char	*dict_name;
	t_dict	*dict;

	nbr = work(argc, argv, &dict_name);
	if (!nbr)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	dict = reader(dict_name);
	eject(&dict);
	sort_dict(&dict);
	if (!prov_dict(dict))
	{
		cl_ean(dict);
		free(nbr);
		return (0);
	}
	nbr_to_text(nbr, dict);
	free(nbr);
	cl_ean(dict);
}
