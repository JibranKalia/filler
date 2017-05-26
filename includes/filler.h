/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:49:07 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/25 19:13:54 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <libft.h>
# define STDIN STDIN_FILENO
# define HEATMAX 100
# define STDERR STDERR_FILENO
# define STDOUT STDOUT_FILENO

typedef struct	s_filler
{
	int			map_x;
	int			map_y;
	int			out_x;
	int			out_y;
	int			out_heatscore;
	char		player;
	char		ai;
	char		**map;
	int			**heatmap;
	char		**piece;
	int			piece_x;
	int			piece_y;
}				t_filler;

void			get_player(t_filler *data);

void			player_move(t_filler *data);

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
void		print_heatmap(t_filler *data);
void		update_heatmap(t_filler *data);
#endif
