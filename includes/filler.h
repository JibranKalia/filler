/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:49:07 by jkalia            #+#    #+#             */
/*   Updated: 2017/06/28 21:24:33 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <libft.h>
# define STDIN STDIN_FILENO
# define HEATMAX 99
# define DIV 1.2
# define STDERR STDERR_FILENO
# define STDOUT STDOUT_FILENO

typedef struct	s_filler
{
	int			map_x;
	int			map_y;
	int			xshift;
	int			yshift;
	int			xend;
	int			yend;
	int			out_x;
	int			out_y;
	int			out_heatscore;
	float		bestdist;
	char		player;
	char		ai;
	char		**map;
	int			**heatmap;
	char		**piece;
	int			piece_x;
	int			piece_y;
	char		**trimpiece;
	int			newx;
	int			newy;
	int			ai_pos_x;
	int			ai_pos_y;
}				t_filler;

void			get_player(t_filler *data);
void			player_move(t_filler *data);
int				get_yshift(t_filler *data);
int				get_xshift(t_filler *data);
int				get_xend(t_filler *data);
int				get_yend(t_filler *data);

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
void			clean_piece(t_filler *data);

/*
** HEATMAP
*/
void			print_heatmap(t_filler *data);
void			update_heatmap(t_filler *data);
#endif
