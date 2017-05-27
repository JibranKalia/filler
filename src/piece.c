/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:27:39 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/26 18:24:07 by jkalia           ###   ########.fr       */
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
	while (++j < data->piece_y)
		ft_dprintf(2, "\t%s\n", data->piece[j]);
	return (0);
}

void	clean_piece(t_filler *data)
{
	int		j;

	j = -1;
	while (++j < data->piece_y)
	{
		free(data->piece[j]);
		data->piece[j] = NULL;
	}
	free(data->piece);
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
