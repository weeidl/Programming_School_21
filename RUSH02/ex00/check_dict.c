/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:51:36 by dwren             #+#    #+#             */
/*   Updated: 2021/02/21 20:54:43 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int		compare_str(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	sort_dict(t_dict **dict)
{
	t_dict	*i;
	t_dict	*j;
	int		flag;

	flag = 1;
	while (flag)
	{
		i = *dict;
		j = (*dict)->next;
		flag = 0;
		while (j)
		{
			if (compare_str(i->nbr, j->nbr) > 0)
			{
				ch_val(&i, &j);
				flag = 1;
			}
			j = j->next;
			i = i->next;
		}
	}
}

void	erase(t_dict **runner)
{
	t_dict	*tmp;

	tmp = *runner;
	if ((*runner)->next)
		(*runner)->next->prev = (*runner)->prev;
	if ((*runner)->prev)
		(*runner)->prev->next = (*runner)->next;
	(*runner) = (*runner)->next;
	free(tmp);
}

void	eject(t_dict **dict)
{
	t_dict	*runner;
	int		size;
	char	*s;

	runner = *dict;
	while (runner)
	{
		s = runner->nbr;
		size = len(runner->nbr);
		if (!(check_poryadok(s, size) || check_n(s) || check_nn(s, size)
					|| check_100(s, size)))
		{
			if (runner == *dict)
				*dict = (*dict)->next;
			erase(&runner);
		}
		else
			runner = runner->next;
	}
}

int		eject_twins(t_dict **dict)
{
	t_dict	*runner;

	runner = *dict;
	while (runner)
	{
		if (runner->next && !compare_str(runner->nbr, runner->next->nbr))
			if (compare_str(runner->text, runner->next->text))
				return (0);
		runner = runner->next;
	}
	return (1);
}
