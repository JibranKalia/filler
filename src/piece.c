/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:27:39 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/27 02:49:39 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

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

int		check_piece(t_filler *data)
{
	int		j;

	j = -1;
	while (++j < data->piece_y)
		ft_dprintf(2, "\t%s\n", data->piece[j]);
	return (0);
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
			data->trimpiece[j][i] =
				data->piece[j + data->xshift][i + data->yshift];
	}
}

int		check_trimpiece(t_filler *data)
{
	int		j;

	j = -1;
	while (++j < data->newy)
		ft_dprintf(2, "%s\t%s\n%s", GREEN, data->trimpiece[j], CLEAR);
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
	data->yshift = get_yshift(data);
	data->xshift = get_xshift(data);
	data->yend = get_yend(data);
	data->xend = get_xend(data);
	data->newx = data->piece_x - data->yshift - data->yend;
	data->newy = data->piece_y - data->xshift - data->xend;
	make_trimpiece(data);
	return (0);
}
