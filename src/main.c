/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:46:50 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/25 17:55:45 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#define TESTPRINT(M, ...) ft_dprintf(2, M, ##__VA_ARGS__);

/**
void	data_cleanup(t_filler *data)
{
	(void)data;
	ft_tbldel(data->map);
	ft_tbldel(data->piece);
}
**/

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
	DEBUG("Player = %d", number);
	ft_strdel(&line);
}

int		main(void)
{
	t_filler	*data;
	char		*line;

	DEBUG("INSIDE MAIN");
	data = ft_memalloc(sizeof(t_filler));
	get_player(data);
	get_mapdem(data);
	make_map(data);
	make_heatmap(data);
	while (get_next_line(STDIN, &line) > 0)
	{
		read_map(data);
		check_map(data);
		read_piece(data);
		check_piece(data);
		update_heatmap(data);
		print_heatmap(data);
		player_move(data);
		check_map(data);
		//		ft_strdel(&line);
	}
	return (0);
}
