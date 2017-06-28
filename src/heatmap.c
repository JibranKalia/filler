/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:18:52 by jkalia            #+#    #+#             */
/*   Updated: 2017/06/28 12:34:25 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	print_heatmap(t_filler *data)
{
	int		j;
	int		i;

	j = -1;
	while (++j < data->map_y)
	{
		i = -1;
		ft_dprintf(2, "\t");
		while (++i < data->map_x)
		{
			ft_dprintf(2, "%s%5d%s", GREEN, data->heatmap[j][i], CLEAR);
		}
		ft_dprintf(2, "\n");
	}
}

int		make_heatmap(t_filler *data)
{
	int		j;
	int		i;
	int		x;
	int		y;

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

void	fill_heatmap(t_filler *data, short level)
{
	int x;
	int y;
	int tmp;

	if (level <= 1)
		return ;
	y = -1;
	while (++y < data->map_y)
	{
		x = -1;
		while (++x < data->map_x)
			if (data->heatmap[y][x] > 0)
			{
				tmp = data->heatmap[y][x];
				if (x - 1 >= 0 && data->heatmap[y][x - 1] < tmp)
					data->heatmap[y][x - 1] = tmp / DIV;
				if (x + 1 < data->map_y && data->heatmap[y][x + 1] < tmp)
					data->heatmap[y][x + 1] = tmp / DIV;
				if (y - 1 >= 0 && data->heatmap[y - 1][x] < tmp)
					data->heatmap[y - 1][x] = tmp / DIV;
				if (y + 1 < data->map_x && data->heatmap[y + 1][x] < tmp)
					data->heatmap[y + 1][x] = tmp / DIV;
			}
	}
	fill_heatmap(data, level / DIV);
}
/**
void	fill_heatmap(t_filler *data, int x, int y)
{
	int		i;
	int		j;
	int		out;

	j = -1;
	while (++j < data->map_y)
	{
		i = -1;
		while (++i < data->map_x)
		{
			out = HEATMAX - (ft_abs(x - i) + ft_abs(y - j));
			HEATMAP = MAX(HEATMAP, out);
		}
	}
}
**/

void	update_heatmap(t_filler *data)
{
	int		i;
	int		j;

	j = -1;
	while (++j < data->map_y)
	{
		i = -1;
		while (++i < data->map_x)
		{
			if (data->map[j][i] == data->ai)
				HEATMAP = HEATMAX;
		}
	}
	fill_heatmap(data, HEATMAX);
}
