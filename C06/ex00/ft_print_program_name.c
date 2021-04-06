/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewayn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:56:25 by ewayn             #+#    #+#             */
/*   Updated: 2021/02/11 19:49:41 by ewayn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_out(char v)
{
	write(1, &v, 1);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 0;
	str = argv[0];
	if (argc > 0)
	{
		while (str[i])
		{
			i++;
		}
		write(1, str, i);
		ft_out('\n');
	}
}
