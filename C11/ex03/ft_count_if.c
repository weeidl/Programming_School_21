/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewayn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 22:22:23 by ewayn             #+#    #+#             */
/*   Updated: 2021/02/17 23:00:32 by ewayn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int (*f)(char*))
{
	int funnc;
	int num;
	int ret;

	funnc = 0;
	num = 0;
	ret = 0;
	while ((i < length) && (tab[i] != '\0'))
	{
		if (f(tab[i]) != 0)
		{
			funnc++;
			num++;
		}
		ret++;
	}
	return (num);
}
