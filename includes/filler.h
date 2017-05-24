/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:49:07 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/23 18:10:17 by jkalia           ###   ########.fr       */
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

#endif
