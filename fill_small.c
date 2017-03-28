#include "fill.h"

static int	move_left_right(t_info *in, int *n, int *m)
{
	int	i;
	int	j;
	int	move;

	move = 0;
	i = (in->left_right == LEFT) ? -100 : in->map_width - 1;
	while (i >= -100 && i < in->map_width)
	{
		j = 0;
		while (j < in->map_high)
		{
			if (put_piece(in, j, i))
			{
				*n = j;
				*m = i;
				move = 1;
				if (in->up_down == UP)
					return (move);
			}
			j++;
		}
		if (move)
			return (move);
		i = (in->left_right == LEFT) ? i + 1 : i - 1;
	}
	return (move);
}


static void	check_direction(t_info *in)
{
	int	i;
	int	j;

	j = (in->left_right == LEFT) ? 0 : in->map_width - 1;
	i = 0;
	while (i < in->map_high)
	{
		if (ft_tolower(in->map[i][j]) == in->player)
		{
			in->left_right = (in->left_right == LEFT) ? RIGHT : LEFT;
			break ;
		}
		i++;
	}
	j = (in->left_right == LEFT) ? 0 : in->map_width - 1;
	i = 0;
	while (i < in->map_high)
	{
		if (ft_tolower(in->map[i][j]) == in->player)
		{
			in->left_right = in->up_down;
//			in->left_right = (in->up_down == UP) ? DOWN : UP;
//			in->up_down = in->left_right;
			break ;
		}
		i++;
	}
}

int			fill_small(t_info *in)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 0;
	if (in->left_right == LEFT || in->left_right == RIGHT)
		check_direction(in);
	if (in->left_right == LEFT || in->left_right == RIGHT)
		result = move_left_right(in, &i, &j);
	else
		result = attack(in, &i, &j);
	ft_printf("%d %d\n", i, j);
	return (result);
}