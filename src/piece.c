/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:27:39 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/27 01:54:18 by jkalia           ###   ########.fr       */
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

void	make_trimpiece(t_filler *data)
{
	int		j;
	int		i;

	data->trimpiece = (char **)ft_memalloc(sizeof(char *) * data->newy);
	j = -1;
	while (++j < data->newy)
		data->trimpiece[j] = ft_strnew(data->newx + 1);
	j = -1;
	while (++j < data->newy)
	{
		i = -1;
		while (++i < data->newx)
			data->trimpiece[j][i] = data->piece[j + data->xshift][i + data->yshift];
	}
}

int		check_trimpiece(t_filler *data)
{
	int		j;

	j = -1;
	while (++j < data->newy)
		dprintf(2, "%s\t%s\n%s", GREEN, data->trimpiece[j], CLEAR);
	return (0);
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
	//check_piece(data);
	data->yshift = get_yshift(data);
	data->xshift = get_xshift(data);
	data->yend = get_yend(data);
	data->xend = get_xend(data);
	data->newx = data->piece_x - data->yshift - data->yend;
	data->newy = data->piece_y - data->xshift - data->xend;
	//ft_dprintf(2, "%s\t yshift = %d\n%s", RED, data->yshift, CLEAR);
	//ft_dprintf(2, "%s\t xshift = %d\n%s", RED, data->xshift, CLEAR);
	//ft_dprintf(2, "%s\t yend = %d\n%s", RED, data->yend, CLEAR);
	//ft_dprintf(2, "%s\t xend = %d\n%s", RED, data->xend, CLEAR);
	//ft_dprintf(2, "%s\t xnew = %d\n%s", RED, data->newx, CLEAR);
	//ft_dprintf(2, "%s\t ynew = %d\n%s", RED, data->newy, CLEAR);
	make_trimpiece(data);
//	check_trimpiece(data);
	return (0);
}
