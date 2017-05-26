/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:27:39 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/25 18:03:46 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		create_piece(t_filler *data)
{
	int		j;
	int		x;
	int		y;

	y = data->piece_y + 1;
	x = data->piece_x + 1;
	data->piece = (char **)ft_memalloc(sizeof(char *) * y);
	MEMCHECK(data->piece);
	j = -1;
	while (++j < y)
	{
		data->piece[j] = (char *)ft_memalloc(sizeof(char) * x);
		MEMCHECK(data->piece[j]);
	}
	return (0);
}

int		check_piece(t_filler *data)
{
	int		j;

	j = -1;
	DEBUG("Check Piece");
	while (++j < data->piece_y)
		dprintf(2, "\t%s\n", data->piece[j]);
	return (0);
}

void	clean_piece(t_filler *data)
{
	int		j;
	int		y;
	int		x;

	y = data->piece_y;
	x = data->piece_x;

	j = -1;
	while (++j < y)
	{
		free(data->piece[j]);
		data->piece[j] = NULL;
	}
	data->piece = NULL;
}

void	fill_piece(t_filler *data)
{
	int		j;
	char	*line;

	j = -1;
	while (++j < data->piece_y)
	{
		get_next_line(STDIN, &line);
		memcpy(data->piece[j], line, data->piece_x);
		ft_strdel(&line);
	}
}

int		read_piece(t_filler *data)
{
	char	*line;
	int		i;

	i = 0;
	DEBUG("Read Piece");
	get_next_line(STDIN, &line);
	while (!ISDIGIT(line[i]))
		++i;
	data->piece_y = ft_atoi(&line[i]);
	while (ISDIGIT(line[i]))
		++i;
	while (!ISDIGIT(line[i]))
		++i;
	data->piece_x = ft_atoi(&line[i]);
	DEBUG("piece_y = %d piece_x = %d", data->piece_y, data->piece_x);
	ft_strdel(&line);
	create_piece(data);
	fill_piece(data);
	return (0);
}
