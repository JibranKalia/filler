/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:49:07 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/24 16:38:53 by jkalia           ###   ########.fr       */
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
	char		**piece;
	int			piece_x;
	int			piece_y;
}				t_filler;

void			get_player(t_filler *data);

/*
** MAP
*/
void			get_mapdem(t_filler *data);
int				make_map(t_filler *data);
void			read_map(t_filler *data);
int				check_map(t_filler *data);
int				make_heatmap(t_filler *data);

/*
** PIECE
*/
int				read_piece(t_filler *data);
int				check_piece(t_filler *data);

#endif
