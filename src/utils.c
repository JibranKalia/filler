/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:46:29 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/24 16:29:09 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	get_player(t_filler *data)
{
	char	*tmp;
	int8_t	number;
	char	*line;

//	DEBUG("Get Player");
	get_next_line(STDIN, &line);
	tmp = ft_strchr(line, 'p');
//	DEBUG("Tmp = %s", tmp);
	++tmp;
	number = ft_atoi(tmp);
	data->player = (number == 1) ? 'O' : 'X';
	data->ai = (number == 1) ? 'X' : 'O';
	DEBUG("Player = %d", number);
	ft_strdel(&line);
}

