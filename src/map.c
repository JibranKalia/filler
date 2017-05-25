/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:27:36 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/24 17:28:10 by jkalia           ###   ########.fr       */
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
	size_t	line_cap;
	int	i;

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
	DEBUG("map_y = %d map_x = %d", data->map_y, data->map_x);
	ft_strdel(&line);
}

int		check_map(t_filler *data)
{
	int	j;
	char	c;

	j = -1;
	while (++j < data->map_y)
	{
		DEBUG("c = %s", data->map[j]);
	}
	return (0);
}

void	read_map(t_filler *data)
{
	int		j;
	int		i;
	int		n;
	int		cpylen;
	char	*line;

	j = -1;
	while (++j < data->map_y)
	{
		i = 0;
		get_next_line(STDIN, &line);
		while (ISDIGIT(line[i]) || ISSPACE(line[i]))
			++i;
		n = ft_strlen(&line[i]);
		memcpy(data->map[j], &line[i], n);
		ft_strdel(&line);
	}
}
