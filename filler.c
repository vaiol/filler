#include "filler.h"

int		put(t_info *in, const int i, const int j)
{
	int	c;
	int	k;
	int l;

	c = 0;
	k = 0;
	while (in->piece[k])
	{
		if (i + k >= in->map_high|| (l = 0))
			return (0);
		while (in->piece[k][l])
		{
			if (j + l >= in->map_width)
				return (0);
			if (in->piece[k][l] == '*')
			{
				(ft_tolower(in->map[i + k][j + l]) == in->player) ? c++ : c;
				if (ft_tolower(in->map[i + k][j + l]) == in->oponent || c > 1)
					return (0);
			}
			l++;
		}
		k++;
	}
	return (c);
}

int		move(t_info *in, t_direction direction, int *n, int *m)
{
	int	i;
	int	j;
	int	move;

	move = 0;
	i = 0;
	while (i < in->map_high)
	{
		j = 0;
		while (j < in->map_width)
		{
			if (put(in, i, j))
			{
				*n = i;
				*m = j;
				move = 1;
				if (direction == UP)
					return (move);
			}
			j++;
		}
		i++;
	}
	return (move);
}

t_direction	check_direction(t_info *in)
{
	int	i;
	int	j;

	i = 0;
	while (i < in->map_high)
	{
		j = 0;
		while (j < in->map_width)
		{
			if (ft_tolower(in->map[i][j]) == in->player)
			{
				if (i < (in->map_high / 2) && j < (in->map_width / 2))
					return (DOWN);
				else
					return (UP);
			}
			j++;
		}
		i++;
	}
	return (UP);
}

int		run(t_info *in)
{
	int	i;
	int	j;
	int	result;
	t_direction direction;

	i = 0;
	j = 0;
	direction = check_direction(in);
	result = move(in, direction, &i, &j);
	ft_printf("%d %d\n", i, j);
	return (result);
}

int	main(void)
{
	t_info	*in;

	in = (t_info *)malloc(sizeof(t_info));
	init_symbols(in);
	init_map(in);
	update_piece(in);
	while (run(in))
	{
		update_map(in);
		update_piece(in);
	}
	remove_map(in);
	remove_piece(in);
	free(in);
	return (0);
}
