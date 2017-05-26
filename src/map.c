/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:27:36 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/25 22:43:10 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		make_map(t_filler *data)
{
	int		j;
	int		x;
	int		y;

	y = data->map_y + 1;
	x = data->map_x + 1;
	data->map = (char **)ft_memalloc(sizeof(char *) * y);
	MEMCHECK(data->map);
	j = -1;
	while (++j < y)
	{
		data->map[j] = ft_strnew(x);
		MEMCHECK(data->map[j]);
	}
	return (0);
}

void	get_mapdem(t_filler *data)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(STDIN, &line);
	while (!ISDIGIT(line[i]))
		++i;
	data->map_y = ft_atoi(&line[i]);
	while (ISDIGIT(line[i]))
		++i;
	while (!ISDIGIT(line[i]))
		++i;
	data->map_x = ft_atoi(&line[i]);
	ft_strdel(&line);
}

int		check_map(t_filler *data)
{
	int		j;

	j = -1;
	while (++j < data->map_y)
		ft_dprintf(2, "%s\t%s\n%s", GREEN, data->map[j], CLEAR);
	return (0);
}

void	read_map(t_filler *data)
{
	int		j;
	char	*line;

	DEBUG("Read Map");
	j = -1;
	while (++j < data->map_y)
	{
		get_next_line(STDIN, &line);
		memcpy(data->map[j], &line[4], data->map_x);
		ft_strdel(&line);
	}
}
