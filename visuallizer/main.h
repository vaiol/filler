/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:02:14 by astepano          #+#    #+#             */
/*   Updated: 2017/03/29 20:02:16 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define FD 0

# include "../libft/libft.h"

typedef struct	s_info
{
	int			map_high;
	int			map_width;
	char		**map;
	char		*p1;
	char		*p2;
	char		*move;
}				t_info;

void			init_players(t_info *in);
void			init_map(t_info *in);
void			update_map(t_info *in);
void			remove_map(t_info *in);
void			print_map(t_info *in);

#endif
