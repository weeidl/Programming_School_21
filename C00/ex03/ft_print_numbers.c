/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewayn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:38:02 by ewayn             #+#    #+#             */
/*   Updated: 2021/02/04 20:58:22 by ewayn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(char i)
{
	

	i = '0';
	while (i <= '9')
	{
		write(1, &i, 1);
		i++;
	}
}
