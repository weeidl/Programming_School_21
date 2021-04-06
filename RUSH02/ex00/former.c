/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   former.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: signacia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:11:37 by signacia          #+#    #+#             */
/*   Updated: 2021/02/21 19:46:17 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

t_dict	*former(char *buffer)
{
	int		i;
	t_dict	*ts_list;
	t_dict	*ts_head;

	i = 0;
	ts_list = create_new_list();
	ts_head = ts_list;
	if (buffer[i] != '\0')
	{
		ts_list->nbr = key_former(buffer, &i);
		ts_list->text = value_former(buffer, &i);
	}
	while (buffer[i] != '\0')
	{
		ts_list->next = create_new_list();
		ts_list->next->prev = ts_list;
		ts_list->next->nbr = key_former(buffer, &i);
		if (buffer[i] == '\0')
			return (ts_head);
		ts_list->next->text = value_former(buffer, &i);
		ts_list = ts_list->next;
	}
	return (ts_head);
}

t_dict	*create_new_list(void)
{
	t_dict	*ts_list;

	ts_list = (t_dict*)malloc(sizeof(t_dict));
	if (ts_list != 0)
	{
		ts_list->prev = 0;
		ts_list->next = 0;
	}
	return (ts_list);
}

char	*key_former(char *buf, int *i)
{
	char	*key;
	int		zero;
	int		nul;

	zero = *i;
	nul = 0;
	while (buf[*i] != ':')
	{
		if (buf[*i] == '\0')
			return ("\0");
		(*i)++;
	}
	key = (char*)malloc(sizeof(char) * (*i - zero + 1));
	while (buf[zero] != ':' && buf[zero] != '\0')
	{
		if (!(buf[zero] >= '0' && buf[zero] <= '9'))
			zero++;
		else
			key[nul++] = buf[zero++];
	}
	key[nul] = '\0';
	(*i)++;
	return (key);
}

char	*value_former(char *buf, int *i)
{
	char	*value;
	int		length;
	int		zero;
	int		nul;

	nul = 0;
	length = 0;
	while (buf[*i] == ' ' || buf[*i] == '\t')
		(*i)++;
	zero = *i;
	while (buf[(*i)++] != '\n')
		length++;
	value = (char*)malloc(sizeof(char) * (length + 1));
	while (buf[zero] != '\n')
		string_corrector(buf, value, &zero, &nul);
	value[nul] = '\0';
	return (value);
}

void	string_corrector(char *buf, char *value, int *zero, int *nul)
{
	if (buf[(*zero) + 1] == '\t')
	{
		value[(*nul) + 1] = ' ';
		buf[(*zero) + 1] = ' ';
	}
	if ((buf[*zero] == ' ') && (buf[*zero + 1] > 0 && buf[*zero + 1] <= 32))
		(*zero)++;
	else if (buf[*zero] == ' ' && buf[*zero + 1] == '\n')
	{
		value[*nul] = '\0';
		(*zero)++;
	}
	else
		value[(*nul)++] = buf[(*zero)++];
}
