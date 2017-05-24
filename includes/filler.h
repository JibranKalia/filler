/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:49:07 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/24 16:09:40 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <libft.h>
# define STDIN STDIN_FILENO

typedef struct	s_filler
{
	t_arr		*file;
	int			map_x;
	int			map_y;
	char		player;
	char		ai;
	char		**map;
	char		**heatmap;
}				t_filler;

int		make_heatmap(t_filler *data);
int		make_map(t_filler *data);
void	get_player(t_filler *data);
void	get_mapdem(t_filler *data);
#endif
