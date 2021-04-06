/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agidget <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 11:28:34 by agidget           #+#    #+#             */
/*   Updated: 2021/02/07 16:36:04 by agidget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static char g_a = 'A';
static char g_b = 'B';
static char g_c = 'C';

void	first_line(int x)
{
	int i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
			write(1, &g_a, 1);
		else if (i == x)
			write(1, &g_c, 1);
		else
			write(1, &g_b, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	body_line(int x, int y)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (j <= y - 2)
	{
		while (i <= x)
		{
			if (i == 1 || i == x)
				write(1, &g_b, 1);
			else
				write(1, " ", 1);
			i++;
		}
		j++;
		write(1, "\n", 1);
		i = 1;
	}
}

void	last_line(int x, int y)
{
	int i;

	if (y > 1)
	{
		i = 1;
		while (i <= x)
		{
			if (i == 1)
				write(1, &g_c, 1);
			else if (i == x)
				write(1, &g_a, 1);
			else
				write(1, &g_b, 1);
			i++;
		}
		write(1, "\n", 1);
	}
}

void	ft_putchar(int x, int y)
{
	first_line(x);
	body_line(x, y);
	last_line(x, y);
}
