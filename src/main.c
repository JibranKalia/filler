/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:46:50 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/24 16:38:36 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#define TESTPRINT(M, ...) ft_dprintf(2, M, ##__VA_ARGS__);

void	data_cleanup(t_filler *data)
{
	(void)data;
}

int		main(void)
{
	t_filler	*data;
	char		*line;

	data = ft_memalloc(sizeof(t_filler *));
	get_player(data);
	get_mapdem(data);
	make_map(data);
	make_heatmap(data);
	while (get_next_line(STDIN, &line) > 0)
	{
		read_map(data);
		check_map(data);
		ft_strdel(&line);
		read_piece(data);
		check_piece(data);
	}
	data_cleanup(data);
	return (0);
}
