/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 01:56:35 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/27 02:00:29 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		get_yshift(t_filler *data)
{
	int		j;
	int		i;
	int		yshift;

	i = -1;
	yshift = 0;
	while (++i < data->piece_x)
	{
		j = -1;
		while (++j < data->piece_y)
		{
			if (data->piece[j][i] == '*')
				return (yshift);
		}
		++yshift;
	}
	return (yshift);
}

int		get_yend(t_filler *data)
{
	int		i;
	int		j;
	int		yend;

	i = data->piece_x - 1;
	yend = 0;
	while (i >= 0)
	{
		j = data->piece_y - 1;
		while (j >= 0)
		{
			if (data->piece[j][i] == '*')
				return (yend);
			--j;
		}
		--i;
		++yend;
	}
	return (yend);
}

int		get_xend(t_filler *data)
{
	int		i;
	int		j;
	int		xend;

	j = data->piece_y - 1;
	xend = 0;
	while (j >= 0)
	{
		i = data->piece_x - 1;
		while (i >= 0)
		{
			if (data->piece[j][i] == '*')
				return (xend);
			--i;
		}
		--j;
		++xend;
	}
	return (xend);
}

int		get_xshift(t_filler *data)
{
	int		i;
	int		j;
	int		xshift;

	j = -1;
	xshift = 0;
	while (++j < data->piece_y)
	{
		i = -1;
		while (++i < data->piece_x)
		{
			if (data->piece[j][i] == '*')
				return (xshift);
		}
		++xshift;
	}
	return (xshift);
}
