/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:18:52 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/24 21:23:42 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	print_heatmap(t_filler *data)
{
	int		j;
	int		i;
	char	c;

	DEBUG("Print Heatmap");
	j = -1;
	while (++j < data->map_y)
	{
		i = -1;
		ft_dprintf(2, "\t%{green}");
		while (++i < data->map_x)
		{
			ft_dprintf(2, "%4d", data->heatmap[j][i]);
		}
		ft_dprintf(2, "\n");
		ft_dprintf(2, "%{eoc}");
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
	data->heatmap = (int **)ft_memalloc(sizeof(int *) * y);
	MEMCHECK(data->heatmap);
	j = -1;
	while (++j < y)
	{
		data->heatmap[j] = (int *)ft_memalloc(sizeof(int) * x);
		MEMCHECK(data->map[j]);
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
