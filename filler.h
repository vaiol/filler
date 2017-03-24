#ifndef FILLER_H
# define FILLER_H

# define FD 0

# include "libft/libft.h"


typedef struct	s_info
{
	char		player;
	char 		oponent;
	int			map_high;
	int			map_width;
	char		**map;
	char		**piece;
}				t_info;

typedef enum	e_move
{
	DOWN,
	UP
}				t_direction;

void	init_symbols(t_info *in);
void	init_map(t_info *in);
void	update_piece(t_info *in);
void	update_map(t_info *in);
void	remove_piece(t_info *in);
void	remove_map(t_info *in);

#endif
