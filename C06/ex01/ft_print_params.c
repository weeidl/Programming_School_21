/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewayn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:01:28 by ewayn             #+#    #+#             */
/*   Updated: 2021/02/11 19:48:41 by ewayn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_out(char v)
{
	write(1, &v, 1);
}

void	ft_strout(char *str)
{
	int		a;

	a = 0;
	while (str[a])
	{
		a++;
	}
	write(1, str, a);
}

int		main(int argc, char **argv)
{
	int		a;
	int		p;

	a = 0;
	p = 1;
	if (argc > 1)
	{
		while (p < argc)
		{
			ft_strout(argv[p]);
			ft_out('\n');
			p++;
		}
	}
}
