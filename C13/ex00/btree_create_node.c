/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewayn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:43:16 by ewayn             #+#    #+#             */
/*   Updated: 2021/02/19 20:43:06 by ewayn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *list;

	list = (t_btree*)malloc(sizeof(t_btree));
	list->left = 0;
	list->right = 0;
	list->item = item;
	return (list);
}
