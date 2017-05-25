/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:38:41 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/25 16:49:33 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

/**
int		is_safe(t_filler *data, int x, int y)
{
	int		i;
	int		j;

	j = -1;
}
**/

void	set_piece(t_filler *data, int x, int y)
{
	int		i;
	int		j;
	int		org_x;

	j = 0;
	org_x = x;
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


void	player_move(t_filler *data)
{
	int		i;
	int		j;


	(void)i;
	(void)j;
	set_piece(data, 1 , 1);
	check_map(data);
	/**
	j = -1;
	while (++j < data->map_y)
	{
		i = -1;
		while (++i < data->map_y);
		{
			if (is_safe(data, i, j) == 1)
				check_priority(data, i, j);
				//DEBUG("SAFE: x = %d\t y = %d", i, j);
				//set_piece(data);
		}
	}
	**/
}
