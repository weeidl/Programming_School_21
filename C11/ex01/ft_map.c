/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewayn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:23:29 by ewayn             #+#    #+#             */
/*   Updated: 2021/02/17 22:43:58 by ewayn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *mas;

	i = 0;
	mas = malloc(sizeof(int) * lenght);
	if (mas == 0)
		return (0);
	while (i < length)
	{
		mas[i] = f(tab[i]);
		i++;
	}
	return (mas);
}
