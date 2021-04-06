/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: signacia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:12:11 by signacia          #+#    #+#             */
/*   Updated: 2021/02/21 19:47:07 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <fcntl.h>

t_dict	*reader(char *path)
{
	int		fd;
	char	buffer[65000];

	fd = open(path, O_RDONLY);
	read(fd, buffer, 65000);
	close(fd);
	return (former(buffer));
}
