/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:46:50 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/24 00:12:12 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#define TESTPRINT(M, ...) ft_dprintf(2, M, ##__VA_ARGS__);

void	data_cleanup(t_filler *data)
{
	(void)data;
}

void	get_player(t_filler *data)
{
	char	*tmp;
	int8_t	number;
	char	*line;

	DEBUG("Get Player");
	get_next_line(STDIN, &line);
	tmp = ft_strchr(line, 'p');
	DEBUG("Tmp = %s", tmp);
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
	DEBUG("CHECK = %s", line);
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

int	check_map(t_filler *data)
{
	int	j;
	int	i;
	char	c;

	j = -1;
	DEBUG("SEG1");
	while (++j < data->map_y)
	{
		i = -1;
		while (++i < data->map_x)
		{
			c = data->map[j][i];
			DEBUG("i = %d\t j = %d\t c = %c", i, j, c);
		}
	}
	DEBUG("SEG2");
	return (0);
}

int	make_map(t_filler *data, char **out)
{
	int	j;
	int	x;
	int	y;
	char	**tmp;

	DEBUG("%{red}Make Map%{eoc}");
	y = data->map_y + 1;
	x = data->map_x + 1;
	tmp = (char **)ft_memalloc(sizeof(char *) * y);
	MEMCHECK(tmp);
	j = -1;
	while (++j < y)
	{
		tmp[j] = ft_strnew(x);
		MEMCHECK(tmp[j]);
		DEBUG("j = %d\t x = %d", j, x); 
	}
	out = tmp;
	return (0);
}

void	skip_xcord(t_filler *data)
{
	char	*line;
	get_next_line(STDIN, &line);
	if (!ft_strstr(line, "Plateau"))
	{
		DEBUG("Ignoring1 = %s", line);
		ft_strdel(&line);
		get_next_line(STDIN, &line);
	}
	DEBUG("Ignoring2 = %s", line);
	ft_strdel(&line);
}

void	read_map(t_filler *data)
{
	int	j;
	int	i;
	int	n;
	int	cpylen;
	char	*line;

	j = -1;
	while (++j < data->map_y)
	{
		i = 0;
		get_next_line(STDIN, &line);
		while (ISDIGIT(line[i]))
			++i;
		++i;
		n = ft_strlen(&line[i]);
		DEBUG("n = %d\t i = %d", n, i);
		memcpy(data->map[j], &line[i], n);
		ft_strdel(&line);
		DEBUG("MAP = %s", data->map[j]);
		sleep(2);
	}
}

int		main(void)
{
	t_filler	*data;
	char		*line;
	int		chk;

	data = ft_memalloc(sizeof(t_filler *));
	get_player(data);
	get_mapdem(data);
	make_map(data, data->map);
	make_map(data, data->heatmap);
	check_map(data);
	while (get_next_line(STDIN, &line) > 0)
	{
		//skip_xcord(data);
		ft_strdel(&line);
		read_map(data);
		sleep(2);
	}
	data_cleanup(data);
	return (0);
}
