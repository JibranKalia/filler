/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:27:39 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/27 00:17:09 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		check_piece(t_filler *data)
{
	int		j;

	j = -1;
	while (++j < data->piece_y)
		ft_dprintf(2, "\t%s\n", data->piece[j]);
	return (0);
}

void	get_piece(t_filler *data)
{
	char	**piece;
	int		i;

	piece = (char **)malloc(sizeof(char *) * data->piece_y);
	i = 0;
	while (i < data->piece_y)
	{
		get_next_line(0, &piece[i]);
		i++;
	}
	data->piece = piece;
}

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


int		read_piece(t_filler *data)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(STDIN, &line);
	while (!ISDIGIT(line[i]))
		++i;
	data->piece_y = ft_atoi(&line[i]);
	while (ISDIGIT(line[i]))
		++i;
	while (!ISDIGIT(line[i]))
		++i;
	data->piece_x = ft_atoi(&line[i]);
	ft_strdel(&line);
	get_piece(data);
	return (0);
}
