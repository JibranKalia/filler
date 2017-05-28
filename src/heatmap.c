/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:18:52 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/28 01:24:51 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	orig_fill(t_filler *data);
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
	data->init = 0;
//	orig_fill(data);
	return (0);
}

#define HEATMAP data->heatmap[j][i]

void	fill_heatmap(t_filler *data, int x, int y, int heat)
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
			out = heat - ((ft_abs(x - i) + ft_abs(y - j)) * 4);
			HEATMAP = MAX(HEATMAP, out);
		}
	}
}

/**
void	orig_fill(t_filler *data)
{
	int		tmp;
	int		j;
	int		i;

	j = data->map_y / 2;
	i = data->map_x / 2;
	tmp = -1;
	while (++tmp < data->map_x)
	{
		fill_heatmap(data, i, tmp);
	}
}
**/

#define YHALF (data->map_y / 2)
#define XHALF (data->map_x / 2)

void	initial_fill(t_filler *data, int i, int j)
{
	int		choosei;
	int		choosej;

	choosei = ((data->map_x - i) >= i) ? data->map_x - 1: 0;
	choosej = ((data->map_y - j) >= j) ? data->map_y - 1: 0;
	ft_dprintf(2, "CHOOSE J = %d\n", choosej);

	if (choosej == 0)
	{
		j = data->map_y;
		while (j > YHALF)
		{
			fill_heatmap(data, XHALF, j, HEATMAX);
			--j;
		}
	}
	else
	{
		j = 0;
		while (j < YHALF)
		{
			fill_heatmap(data, XHALF, j, HEATMAX);
			++j;
		}
	}
	if (choosei == 0)
	{
		i = data->map_x;
		while (i > XHALF)
		{
			fill_heatmap(data, i, YHALF, HEATMAX);
			--i;
		}
	}
	else
	{
		i = 0;
		while (i < XHALF)
		{
			fill_heatmap(data, i, YHALF, HEATMAX);
			++i;
		}
	}
	data->init = 1;
}

void	nested_loop(t_filler *data, int i, int j)
{
	if (data->init == 0)
		initial_fill(data, i, j);
	fill_heatmap(data, i, j, HEATMAX);
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
			{
				nested_loop(data, i, j);
			}
		}
	}
}
