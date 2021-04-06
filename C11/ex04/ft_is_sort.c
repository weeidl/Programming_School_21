/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewayn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 23:01:46 by ewayn             #+#    #+#             */
/*   Updated: 2021/02/17 23:35:00 by ewayn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int ret;
	int jej;
	int ioi;

	ioi = 0;
	jej = 0;
	ret = 0;
	while (ret < (length - 1))
	{
		if (f(tab[ret], tab[ret + 1]) > 0)
			ioi++;
		if (f(tab[ret], tab[ret + 1]) < 0)
			jej++;
		ret++;
	}
	if ((ioi > 0) && (jej > 0))
		return (1);
	else
		return (0);
}
