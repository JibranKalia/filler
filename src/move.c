/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:38:41 by jkalia            #+#    #+#             */
/*   Updated: 2017/06/28 21:23:18 by jkalia           ###   ########.fr       */
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
	while (++j < data->newy)
	{
		i = -1;
		while (++i < data->newx)
		{
			if (data->trimpiece[j][i] == '*')
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

void	get_ai_pos(t_filler *data)
{
	int			i;
	int			j;

	j = -1;
	while (++j < data->map_y)
	{
		i = -1;
		while (++i < data->map_x)
		{
			if (TOUPPER(data->map[j][i]) == data->ai)
			{
				data->ai_pos_x = i;
				data->ai_pos_y = j;
				return ;
			}
		}
	}
}

int		calculate_heatscore(t_filler *data, int x, int y)
{
	int		score;
	int		i;
	int		j;

	score = 0;
	j = -1;
	while (++j < data->newy)
	{
		i = -1;
		while (++i < data->newx)
		{
			if (data->trimpiece[j][i] == '*')
				score += data->heatmap[y + j][x + i];
		}
	}
	return (score);
}

#define SQUARE(x) ((x)*(x))

void	check_priority(t_filler *data, int x, int y)
{
	int		tmpheatscore;
	float	dist;

	tmpheatscore = calculate_heatscore(data, x, y);
	if (data->out_heatscore < tmpheatscore)
	{
		data->out_x = x - data->yshift;
		data->out_y = y - data->xshift;
		data->out_heatscore = tmpheatscore;
	}
	if (data->out_heatscore == 0)
	{
		get_ai_pos(data);
		dist = ft_sqrtf(SQUARE(x - data->ai_pos_x)
				+ SQUARE(y - data->ai_pos_y));
		if (data->bestdist > dist)
		{
			data->bestdist = dist;
			data->out_x = x - data->yshift;
			data->out_y = y - data->xshift;
		}
	}
}

void	player_move(t_filler *data)
{
	int		i;
	int		j;

	j = -1;
	while (++j + (data->newy - 1) < data->map_y)
	{
		i = -1;
		while (++i + (data->newx - 1) < data->map_x)
		{
			if (is_safe(data, i, j) == 1)
				check_priority(data, i, j);
		}
	}
	ft_dprintf(1, "%d %d\n", data->out_y, data->out_x);
	data->out_heatscore = 0;
	data->out_y = 0;
	data->out_x = 0;
	data->bestdist = data->map_x * data->map_y;
}
