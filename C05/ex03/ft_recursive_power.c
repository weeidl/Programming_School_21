/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewayn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 05:48:30 by ewayn             #+#    #+#             */
/*   Updated: 2021/02/10 18:27:23 by ewayn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else if (power < 0)
		return (1) / (nb * ft_recursive_power(1 / nb, power + 1));
	return (nb * ft_recursive_power(nb, power - 1));
}
