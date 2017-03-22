#ifndef FILLER_H
# define FILLER_H

# define FD 0

# include "fcntl.h"
# include "libft/libft.h"


typedef struct	s_info
{
	char		p_symbol;
	char 		o_symbol;
	int			map_high;
	char		**map;
	char		**piece;
}				t_info;

void	init_symbols(t_info *in);
void	init_map(t_info *in);
void	update_piece(t_info *in);
void	update_map(t_info *in);
void	remove_piece(t_info *in);
void	remove_map(t_info *in);

#endif

//stdin  0
//stdout 1

