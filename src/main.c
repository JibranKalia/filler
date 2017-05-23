/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:46:50 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/22 17:01:12 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#define TESTPRINT(M, ...) ft_dprintf(2, M, ##__VA_ARGS__);

void	testprint(char *message, ...)
{
	va_list		ap;
}

void	file_clean(void *elm)
{
	(void)elm;
}

void	data_cleanup(t_filler *data)
{
	free(data);
}

void	get_player(char *line, t_filler *data)
{
	char	*tmp;

	DEBUG("GETPLAYER");
	tmp = ft_strchr(line, 'p');
	++tmp;
	data->player_no = ft_atoi(tmp);
	DEBUG("Player No = %d", data->player_no);
	free(line);
	line = NULL;
}

void	get_mapdem(char *line, t_filler *data)
{
	DEBUG("GETMAPDEM");
	free(line);
	line = NULL;
}

int		main(void)
{
	t_filler	*data;
	char		*line;
	int			chk;

	data = ft_memalloc(sizeof(t_filler *));
	while (get_next_line(0, &line) > 0)
	{
		DEBUG("THIS: %s", line);
		if (ft_strstr(line, "$$$") != NULL)
			get_player(line, data);
		if (ft_strstr(line, "Plateau") != NULL)
			get_mapdem(line, data);
		DEBUG("HERE");
	}
	//data_cleanup(data);
	return (0);
}
