/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:46:50 by jkalia            #+#    #+#             */
/*   Updated: 2017/06/30 16:12:55 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#include <limits.h>

void	get_player(t_filler *data)
{
	char	*tmp;
	int8_t	number;
	char	*line;

	get_next_line(STDIN, &line);
	tmp = ft_strchr(line, 'p');
	++tmp;
	number = ft_atoi(tmp);
	data->player = (number == 1) ? 'O' : 'X';
	data->ai = (number == 1) ? 'X' : 'O';
	ft_strdel(&line);
}

void	skip_line(char **line)
{
	if (!ft_strncmp(*line, "Plateau", 7))
	{
		ft_strdel(line);
		get_next_line(STDIN, line);
	}
	ft_strdel(line);
}

int		main(void)
{
	t_filler	*data;
	char		*line;

	data = ft_memalloc(sizeof(t_filler));
	data->bestdist = INT_MAX;
	get_player(data);
	get_mapdem(data);
	make_map(data);
	make_heatmap(data);
	while (get_next_line(STDIN, &line) > 0)
	{
		skip_line(&line);
		read_map(data);
		read_piece(data);
		update_heatmap(data);
		player_move(data);
	}
	return (0);
}
