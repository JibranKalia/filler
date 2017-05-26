/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:38:41 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/25 19:03:20 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

#define MAP data->map[y][x]
#define PIECE data->piece[j][i]

int		is_safe(t_filler *data, int x, int y)
{
	int		i;
	int		j;
	int		track_o;
	int		org_x;

	j = 0;
	track_o = 0;
	org_x = x;
	while (j < data->piece_y)
	{
		i = 0;
		x = org_x;
		while (i < data->piece_x)
		{
			if (MAP == data->player && PIECE == '*')
				++track_o;
			if (MAP == data->ai)
				return (-1);
			++x;
			++i;
			if (x > data->map_x)
				return (-1);
		}
		++j;
		++y;
			if (y > data->map_y)
				return (-1);
	}
	if (track_o != 1)
		return (-1);
	return (1);
}


void	set_piece(t_filler *data, int x, int y)
{
	int		i;
	int		j;
	int		org_x;

	j = 0;
	org_x = x;
	DEBUG("SET PIECE x = %d\t y = %d", x, y);
	while (j < data->piece_y)
	{
		i = 0;
		x = org_x;
		while (i < data->piece_x)
		{
			data->map[y][x] = data->piece[j][i];
			++x;
			++i;
		}
		++j;
		++y;
	}
}

int		calculate_heatscore(t_filler *data, int x, int y)
{
	int		score;
	int		i;
	int		j;
	int		org_x;

	score = 0;
	j = 0;
	org_x = x;
	while (j < data->piece_y)
	{
		i = 0;
		x = org_x;
		while (i < data->piece_x)
		{
			if (PIECE == '*')
				score += data->heatmap[y][x];
			++x;
			++i;
		}
		++j;
		++y;
	}
	return (score);
}

void	check_priority(t_filler *data, int x, int y)
{
	int		tmpheatscore;

	DEBUG("CHECK PRIORITY x = %d\t y = %d", x, y);
	tmpheatscore = calculate_heatscore(data, x, y);
	if (data->out_heatscore < tmpheatscore)
	{
		data->out_x = x;
		data->out_y = y;
		data->out_heatscore = tmpheatscore;
		DEBUG("Heatscore = %d", data->out_heatscore);
	}
}

void	player_move(t_filler *data)
{
	int		i;
	int		j;


	j = -1;
	while (++j < data->map_y)
	{
		i = -1;
		while (++i < data->map_x)
		{
			if (is_safe(data, i, j) == 1)
				check_priority(data, i, j);
		}
	}
	set_piece(data, data->out_x , data->out_y);
	dprintf(2, "%s x = %d\t y = %d%s\n", RED, data->out_x, data->out_y, CLEAR);
	printf("%d %d\n", data->out_x, data->out_y);
}
