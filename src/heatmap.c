/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:18:52 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/26 19:05:59 by jkalia           ###   ########.fr       */
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
			ft_dprintf(2, "%s%3d%s", GREEN, data->heatmap[j][i], CLEAR);
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

void	fill_heatmap(t_filler *data, int x, int y)
{
	int		i;
	int		j;

	j = -1;
	while (++j < data->map_y)
	{
		i = -1;
		while (++i < data->map_x)
		{
			HEATMAP = MAX(HEATMAP, HEATMAX - (ft_abs(x - i) + ft_abs(y - j)));
		}
	}
}

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
				fill_heatmap(data, i, j);
		}
	}
}
