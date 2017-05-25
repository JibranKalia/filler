/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:18:52 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/24 19:49:11 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	print_heatmap(t_filler *data)
{
	int		j;
	int		i;
	char	c;

	DEBUG("%{red}Print Heatmap%{eoc}");
	j = -1;
	while (++j < data->map_y)
	{
		i = -1;
		while (++i < data->map_x)
			ft_putnbr(data->heatmap[j][i]);
		ft_putstr("\n");
	}
}

int		make_heatmap(t_filler *data)
{
	int		j;
	int		x;
	int		y;

	y = data->map_y + 1;
	x = data->map_x + 1;
	data->heatmap = (int **)ft_memalloc(sizeof(int *) * y);
	MEMCHECK(data->heatmap);
	j = -1;
	while (++j < y)
	{
		data->heatmap[j] = (int *)ft_memalloc(sizeof(int *) * y);
		MEMCHECK(data->map[j]);
	}
	return (0);
}
