#include "filler.h"

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

int		check_shield(t_info *in, int high)
{
	int	i;
	int j;
	int	count;

	count = 0;
	i = 0;
	while (in->piece[i])
	{
		j = 0;
		while (in->piece[i][j])
		{
			if (in->piece[i][j] == '*')
			{
				if (high + i == in->start_high)
					count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int		build_shield(t_info *in, int *n, int *m)
{
	int	i;
	int	j;
	int	shields;
	int c;

	shields = 0;
	i = in->start_high - 1;
	while (i >= 0)
	{
		j = (in->left_right == LEFT) ? 0 : in->map_width - 1;
		while (j < in->map_width && j >= 0)
		{
			if (put_piece(in, i, j))
			{
				if ((c = check_shield(in, i)) > shields && (shields = c))
				{
					*n = i;
					*m = j;
				}
			}
			j = (in->left_right == LEFT) ? j + 1 : j - 1;
		}
		i--;
	}
	return (shields);
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
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 0;
	result = build_shield(in, &i, &j);
	if (!result)
		result = attack(in, &i, &j);
	ft_printf("%d %d\n", i, j);
	return (result);
}
