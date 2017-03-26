#ifndef FILLER_H
# define FILLER_H

# define FD 0

# include "libft/libft.h"

typedef enum	e_move
{
	DOWN,
	UP,
	LEFT,
	RIGHT
}				t_direction;

typedef struct	s_info
{
	char		player;
	char 		oponent;
	int			map_high;
	int			map_width;
	char		**map;
	char		**piece;
	t_direction	main_direction;
	t_direction	sub_direction;
	int			begin_high;
}				t_info;

void	init_symbols(t_info *in);
void	init_map(t_info *in);
void	init_direction(t_info *in);
void	update_piece(t_info *in);
void	update_map(t_info *in);
void	remove_piece(t_info *in);
void	remove_map(t_info *in);

#endif
