/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewayn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:21:49 by ewayn             #+#    #+#             */
/*   Updated: 2021/02/16 21:24:55 by ewayn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_display(char *name)
{
	int		namefile;
	char	output;

	namefile = open(name, O_RDONLY);
	if (namefile == -1)
	{
		write(2, "Cannot read file.\n", 19);
		return ;
	}
	while (read(namefile, &output, 1))
	{
		write(1, &output, 1);
	}
	close(namefile);
}

int		main(int argc, char *argv[])
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
	}
	else
	{
		ft_display(argv[1]);
	}
	return (0);
}
