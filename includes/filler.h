/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:49:07 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/22 16:39:51 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <libft.h>

typedef struct	s_filler
{
	t_arr		*file;
	int			map_x;
	int			map_y;
	int8_t		player_no;
}				t_filler;

#endif
