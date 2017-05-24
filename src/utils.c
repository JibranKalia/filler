/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:46:29 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/24 16:09:46 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		make_heatmap(t_filler *data)
{
	int		j;
	int		x;
	int		y;

	y = data->map_y + 1;
	x = data->map_x + 1;
	data->heatmap = (char **)ft_memalloc(sizeof(char *) * y);
	MEMCHECK(data->heatmap);
	j = -1;
	while (++j < y)
	{
		data->heatmap[j] = ft_strnew(x);
		MEMCHECK(data->map[j]);
	}
	return (0);
}

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

void	get_player(t_filler *data)
{
	char	*tmp;
	int8_t	number;
	char	*line;

//	DEBUG("Get Player");
	get_next_line(STDIN, &line);
	tmp = ft_strchr(line, 'p');
//	DEBUG("Tmp = %s", tmp);
	++tmp;
	number = ft_atoi(tmp);
	data->player = (number == 1) ? 'O' : 'X';
	data->ai = (number == 1) ? 'X' : 'O';
	DEBUG("Player = %d", number);
	ft_strdel(&line);
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
