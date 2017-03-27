#include "fill.h"

int		put_piece(t_info *in, const int i, const int j)
{
	int	c;
	int	k;
	int l;

	c = 0;
	k = 0;
	while (in->piece[k])
	{
		l = 0;
		while (in->piece[k][l])
		{
			if (in->piece[k][l] == '*')
			{
				if ((i + k >= in->map_high || i + k < 0)
					|| (j + l >= in->map_width || j + l < 0))
					return (0);
				(ft_tolower(in->map[i + k][j + l]) == in->player) ? c++ : c;
				if (ft_tolower(in->map[i + k][j + l]) == in->enemy || c > 1)
					return (0);
			}
			l++;
		}
		k++;
	}
	return (c);
}



int		attack(t_info *in, int *n, int *m)
{
	int	i;
	int	j;
	int	move;

	move = 0;
	i = -100;
	while (i < in->map_high)
	{
		j = -100;
		while (j < in->map_width)
		{
			if (put_piece(in, i, j))
			{
				*n = i;
				*m = j;
				move = 1;
				if (in->up_down == UP)
					return (move);
			}
			j++;
		}
		i++;
	}
	return (move);
}

int		fill(t_info *in)
{
	if (in->map_high > 50)
		return (fill_big(in));
	return (fill_small(in));
}


int	main(void)
{
	t_info	*in;

	in = (t_info *)malloc(sizeof(t_info));
	init_symbols(in);
	init_map(in);
	init_direction(in);
	update_piece(in);
	while (fill(in))
	{
		update_map(in);
		update_piece(in);
	}
	remove_map(in);
	remove_piece(in);
	free(in);
	return (0);
}
