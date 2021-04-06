/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewayn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:57:14 by ewayn             #+#    #+#             */
/*   Updated: 2021/02/11 19:51:56 by ewayn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_out(char v)
{
	write(1, &v, 1);
}

void	ft_strout(char *str)
{
	int a;

	a = 0;
	while (str[a])
		a++;
	write(1, str, a);
}

int		main(int argc, char **argv)
{
	int		p;

	p = 1;
	p = argc - 1;
	if (argc > 0)
	{
		while (p > 0)
		{
			ft_strout(argv[p]);
			ft_out('\n');
			p--;
		}
	}
}
