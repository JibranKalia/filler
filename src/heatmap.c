/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:18:52 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/25 18:53:18 by jkalia           ###   ########.fr       */
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

#define HEATMAP data->heatmap[j][i]

void	fill_heatmap(t_filler *data, int x, int y)
{
	int		curr;
	int		i;
	int		j;

	curr = 100;
	j = -1;
	while (++j < data->map_y)
	{
		i = -1;
		while (++i < data->map_x)
		{
			HEATMAP = MAX(HEATMAP, curr - (ft_abs(x - i) + ft_abs(y - j)));
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
		}
	}
}
