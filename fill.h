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
	char 		enemy;
	int			map_high;
	int			map_width;
	int			start_high;
	char		**map;
	char		**piece;
	t_direction	up_down;
	t_direction	left_right;
}				t_info;

void	init_symbols(t_info *in);
void	init_map(t_info *in);
void	init_direction(t_info *in);
void	update_piece(t_info *in);
void	update_map(t_info *in);
void	remove_piece(t_info *in);
void	remove_map(t_info *in);
int		put_piece(t_info *in, const int i, const int j);
int		attack(t_info *in, int *n, int *m);
int		fill_big(t_info *in);
int		fill_small(t_info *in);
int		fill(t_info *in);

#endif
