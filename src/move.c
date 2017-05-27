/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:38:41 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/26 19:36:38 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

#define PIECE_PT data->piece[j][i] == '*'
#define PIECE data->piece[j][i]

int		is_safe(t_filler *data, int x, int y)
{
	int		i;
	int		j;
	int		track;

	track = 0;
	j = -1;
	while (++j < data->piece_y)
	{
		i = -1;
		while (++i < data->piece_x)
		{
			if (data->piece[j][i] == '*')
			{
				if (data->map[y + j][x + i] == data->player)
					++track;
				else if (data->map[y + j][x + i] == data->ai)
					return (-1);
			}
		}
	}
	return ((track == 1) ? 1 : -1);
}

void	set_piece(t_filler *data, int x, int y)
{
	int		i;
	int		j;

	j = -1;
	while (++j < data->piece_y)
	{
		i = -1;
		while (++i < data->piece_x)
			data->map[y + j][x + i] = data->piece[j][i];
	}
}

int		calculate_heatscore(t_filler *data, int x, int y)
{
	int		score;
	int		i;
	int		j;

	score = 0;
	j = -1;
	while (++j < data->piece_y)
	{
		i = -1;
		while (++i < data->piece_x)
		{
			if (data->piece[j][i] == '*')
				score += data->heatmap[y + j][x + i];
		}
	}
	return (score);
}

void	check_priority(t_filler *data, int x, int y)
{
	int		tmpheatscore;

//	DEBUG("CHECK PRIORITY = %d y = %d", x, y);
	tmpheatscore = calculate_heatscore(data, x, y);
	if (data->out_heatscore <= tmpheatscore)
	{
		data->out_x = x;
		data->out_y = y;
		data->out_heatscore = tmpheatscore;
	}
}

void	player_move(t_filler *data)
{
	int		i;
	int		j;

	j = -1;
	while (++j + (data->piece_y - 1) < data->map_y)
	{
		i = -1;
		while (++i + (data->piece_x - 1) < data->map_x)
		{
			if (is_safe(data, i, j) == 1)
				check_priority(data, i, j);
		}
	}
	ft_dprintf(1, "%d %d\n", data->out_y, data->out_x);
//	ft_dprintf(2, "\tOUT %s%d %d\n%s", GREEN, data->out_y, data->out_x, CLEAR);
	data->out_heatscore = 0;
}
