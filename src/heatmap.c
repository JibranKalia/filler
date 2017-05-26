/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:18:52 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/25 17:19:35 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	print_heatmap(t_filler *data)
{
	int		j;
	int		i;

	DEBUG("Print Heatmap");
	j = -1;
	while (++j < data->map_y)
	{
		i = -1;
		dprintf(2, "\t");
		while (++i < data->map_x)
		{
			dprintf(2, "%s%3d%s", GREEN, data->heatmap[j][i], CLEAR);
		}
		dprintf(2, "\n");
	}
}

int		make_heatmap(t_filler *data)
{
	int		j;
	int		i;
	int		x;
	int		y;

	DEBUG("Make Heatmap");
	y = data->map_y + 1;
	x = data->map_x + 1;
	data->heatmap = (int **)malloc(sizeof(int *) * y);
	MEMCHECK(data->heatmap);
	j = -1;
	while (++j < y)
	{
		data->heatmap[j] = (int *)malloc(sizeof(int) * x);
		MEMCHECK(data->heatmap[j]);
		i = -1;
		while (++i < x)
			data->heatmap[j][i] = 0;
	}
	return (0);
}

void	fill_heatmap(t_filler *data, int x, int y)
{
	int		i;
	int		j;
	int		curr;

	j = y;
	curr = 100;
	DEBUG("FILL Heatmap x = %d\t y = %d", x, y);
	while (j >= 0)
	{
		data->heatmap[j][x] = MAX(data->heatmap[j][x], curr);
		--j;
		if (curr > 0)
			--curr;
	}
	curr = 100;
	j = y;
	while (j < data->map_y)
	{
		data->heatmap[j][x] = MAX(data->heatmap[j][x], curr);
		if (curr > 0)
			--curr;
		++j;
	}
	j = -1;
	while (++j < data->map_y)
	{
		i = x;
		curr = data->heatmap[j][x];
		while (i < data->map_x)
		{
			data->heatmap[j][i] = MAX(data->heatmap[j][i], curr);
			if (curr > 0)
				--curr;
			++i;
		}
		i = x;
		curr = data->heatmap[j][x];
		while (i >= 0)
		{
			data->heatmap[j][i] = MAX(data->heatmap[j][i], curr);
			if (curr > 0)
				--curr;
			--i;
		}
	}
}

void	update_heatmap(t_filler *data)
{
	int		i;
	int		j;

	j = -1;
	DEBUG("Update Heatmap");
	DEBUG("Player = %c\t AI = %c", data->player, data->ai);
	while (++j < data->map_y)
	{
		i = -1;
		while (++i < data->map_x)
		{
			if (data->map[j][i] == data->ai)
				fill_heatmap(data, i, j);
//			DEBUG("%c\t%c", data->map[j][i], data->ai);
		}
	}
}
