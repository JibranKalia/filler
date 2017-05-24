/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:46:50 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/24 16:09:44 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#define TESTPRINT(M, ...) ft_dprintf(2, M, ##__VA_ARGS__);

void	data_cleanup(t_filler *data)
{
	(void)data;
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
		while (ISDIGIT(line[i]) || ISSPACE(line[i]))
			++i;
		n = ft_strlen(&line[i]);
		memcpy(data->map[j], &line[i], n);
		ft_strdel(&line);
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
	make_map(data);
	make_heatmap(data);
	while (get_next_line(STDIN, &line) > 0)
	{
		read_map(data);
		check_map(data);
		ft_strdel(&line);
		sleep(2);
	}
	data_cleanup(data);
	return (0);
}
