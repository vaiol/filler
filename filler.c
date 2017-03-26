#include "filler.h"

//int		moverl(t_info *in, int *n, int *m)
//{
//	int	i;
//	int	j;
//	int	move;
//
//	move = 0;
//	i = (in->sub_direction == LEFT) ? 0 : in->map_width - 1;
//	while (i >= 0 && i < in->map_width)
//	{
//		j = 0;
//		while (j < in->map_high)
//		{
//			if (put(in, j, i))
//			{
//				*n = j;
//				*m = i;
//				move = 1;
//				if (in->main_direction == UP)
//					return (move);
//			}
//			j++;
//		}
//		if (move)
//			return (move);
//		i = (in->sub_direction == LEFT) ? i + 1 : i - 1;
//	}
//	return (move);
//}
//
//
//void	check_direction(t_info *in)
//{
//	int	i;
//	int	j;
//
//	j = (in->sub_direction == LEFT) ? 0 : in->map_width - 1;
//	i = 0;
//	while (i < in->map_high)
//	{
//		if (ft_tolower(in->map[i][j]) == in->player)
//		{
//			in->sub_direction = (in->sub_direction == LEFT) ? RIGHT : LEFT;
//			break ;
//		}
//		i++;
//	}
//	j = (in->sub_direction == LEFT) ? 0 : in->map_width - 1;
//	i = 0;
//	while (i < in->map_high)
//	{
//		if (ft_tolower(in->map[i][j]) == in->player)
//		{
//			in->sub_direction = (in->main_direction == UP) ? DOWN : UP;
//			in->main_direction = in->sub_direction;
//			break ;
//		}
//		i++;
//	}
//}

int		put(t_info *in, const int i, const int j)
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
				if (i + k >= in->map_high || j + l >= in->map_width)
					return (0);
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

int		check_shield(t_info *in, int i)
{
	int	k;
	int l;
	int	c;

	c = 0;
	k = 0;
	while (in->piece[k])
	{
		l = 0;
		while (in->piece[k][l])
		{
			if (in->piece[k][l] == '*')
			{
				if (i + k == in->begin_high)
					c++;
			}
			l++;
		}
		k++;
	}
	return (c);
}

int		move_shield(t_info *in, int *n, int *m)
{
	int	i;
	int	j;
	int	move;
	int	best_shield;
	int shields;

	best_shield = 0;
	move = 0;
	i = in->begin_high - 1;
	while (i >= 0)
	{
		j = (in->sub_direction == LEFT) ? 0 : in->map_width - 1;
		while (j < in->map_width && j >= 0)
		{
			if (put(in, i, j))
			{
				shields = check_shield(in, i);
				if (shields > best_shield)
				{
					*n = i;
					*m = j;
					best_shield = shields;
					move = 1;
				}
			}
			j = (in->sub_direction == LEFT) ? j + 1 : j - 1;
		}
		i--;
	}
	return (move);
}



int		move(t_info *in, int *n, int *m)
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
				if (in->main_direction == UP)
					return (move);
			}
			j++;
		}
		i++;
	}
	return (move);
}

int		run(t_info *in)
{
	int	i;
	int	j;
	int	result;
//	int	tmp;

	i = 0;
	j = 0;
//	if (in->sub_direction == LEFT || in->sub_direction == RIGHT)
//		check_direction(in);
//	if (in->sub_direction == LEFT || in->sub_direction == RIGHT)
//		result = moverl(in, &i, &j);
//	else
	result = move_shield(in, &i, &j);
	if (!result)
		result = move(in, &i, &j);
	ft_printf("%d %d\n", i, j);
	return (result);
}

int	main(void)
{
	t_info	*in;

	in = (t_info *)malloc(sizeof(t_info));
	init_symbols(in);
	init_map(in);
	init_direction(in);
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
