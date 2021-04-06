/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 11:26:29 by dwren             #+#    #+#             */
/*   Updated: 2021/02/21 19:57:08 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_poryadok(char *nbr, int size)
{
	int		i;

	if (size < 4)
		return (0);
	if (nbr[0] != '1')
		return (0);
	i = 1;
	while (nbr[i])
	{
		if (nbr[i] != '0' || nbr[i + 1] != '0' || nbr[i + 2] != '0')
			return (0);
		i += 3;
	}
	return (1);
}

int		check_n(char *nbr)
{
	if (nbr[0] >= '0' && nbr[0] <= '9' && nbr[1] == '\0')
		return (1);
	return (0);
}

int		check_nn(char *nbr, int size)
{
	if (size > 2)
		return (0);
	if (nbr[0] == '1' && nbr[1] >= '0' && nbr[1] <= '9' && nbr[2] == '\0')
		return (1);
	if (nbr[0] >= '2' && nbr[0] <= '9' && nbr[1] == '0' && nbr[2] == '\0')
		return (1);
	return (0);
}

int		len(char *s)
{
	int		size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

int		check_100(char *nbr, int size)
{
	if (size < 3)
		return (0);
	if (nbr[0] == '1' && nbr[1] == '0' && nbr[2] == '0' && nbr[3] == '\0')
		return (1);
	return (0);
}
