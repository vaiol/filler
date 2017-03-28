#include "fill.h"

static int	check_shield(t_info *in, int high, int width)
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
				if ((high + i == in->player_high
					 || high + i == in->enemy_high)
					&& ft_tolower(in->map[i + high][j + width]) != in->player)
					count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

static int	build_shield(t_info *in, int *n, int *m)
{
	int	i;
	int	j;
	int	shields;
	int c;

	shields = 0;
	i = -100;
	while (i <= in->player_high)
	{
		j = (in->left_right == LEFT) ? -100 : in->map_width - 1;
		while (j < in->map_width && j >= -100)
		{
			if (put_piece(in, i, j))
			{
				if ((c = check_shield(in, i, j)) > shields && (shields = c))
				{
					*n = i;
					*m = j;
				}
			}
			j = (in->left_right == LEFT) ? j + 1 : j - 1;
		}
		i++;
	}
	return (shields);
}


//static int	count_enemy(t_info *in, int i, int j)
//{
//	int	count;
//
//	count = 0;
//	if (i > 0 && ft_tolower(in->map[i - 1][j]) == in->enemy)
//		count++;
//	if (i > 0 && ft_tolower(in->map[i - 1][j + 1]) == in->enemy)
//		count++;
//	if (j > 0 && ft_tolower(in->map[i][j - 1]) == in->enemy)
//		count++;
//	if (j > 0 && ft_tolower(in->map[i + 1][j - 1]) == in->enemy)
//		count++;
//	if (i > 0 && j > 0 && ft_tolower(in->map[i - 1][j - 1]) == in->enemy)
//		count++;
//	if (in->map[i + 1] && ft_tolower(in->map[i + 1][j]) == in->enemy)
//		count++;
//	if (ft_tolower(in->map[i][j + 1]) == in->enemy)
//		count++;
//	if (in->map[i + 1] && ft_tolower(in->map[i + 1][j + 1]) == in->enemy)
//		count++;
//	return (count);
//}
//
//static int	check_enemy(t_info *in, int high, int width)
//{
//	int	i;
//	int j;
//	int	count;
//
//	count = 0;
//	i = 0;
//	while (in->piece[i])
//	{
//		j = 0;
//		while (in->piece[i][j])
//		{
//			if (in->piece[i][j] == '*')
//			{
//				if (in->up_down == UP && i + high > in->player_high)
//					return (0);
//				if (in->up_down == DOWN && i + high < in->player_high)
//					return (0);
//				count += count_enemy(in, i + high, j + width);
//			}
//			j++;
//		}
//		i++;
//	}
//	return (count);
//}
//
//static int	check_between(t_info *in, int high)
//{
//	int	i;
//	int j;
//
//	i = 0;
//	while (in->piece[i])
//	{
//		j = 0;
//		while (in->piece[i][j])
//		{
//			if (in->piece[i][j] == '*')
//			{
//				if (in->up_down == UP
//					&& (i + high > in->enemy_high || i + high < in->player_high))
//					return (0);
//				if (in->up_down == DOWN
//					&& (i + high < in->enemy_high || i + high > in->player_high))
//					return (0);
//			}
//			j++;
//		}
//		i++;
//	}
//	return (1);
//}
//
//
//static int	attack_between_shields(t_info *in, int *n, int *m)
//{
//	int	i;
//	int	j;
//	int	enemy;
//
//	enemy = 0;
//	i = -100;
//	while (i <= in->player_high)
//	{
//		j = (in->left_right == LEFT) ? -100 : in->map_width - 1;
//		while (j < in->map_width && j >= -100)
//		{
//			if (put_piece(in, i, j))
//			{
//				if (check_between(in, i))
//				{
//					*n = i;
//					*m = j;
//				}
//			}
//			j = (in->left_right == LEFT) ? j + 1 : j - 1;
//		}
//		i++;
//	}
//	return (enemy);
//}
//
//static int	attack_enemy(t_info *in, int *n, int *m)
//{
//	int	i;
//	int	j;
//	int	enemy;
//	int c;
//
//	enemy = 0;
//	i = -100;
//	while (i <= in->player_high)
//	{
//		j = (in->left_right == LEFT) ? -100 : in->map_width - 1;
//		while (j < in->map_width && j >= -100)
//		{
//			if (put_piece(in, i, j))
//			{
//				if ((c = check_enemy(in, i, j)) > enemy && (enemy = c))
//				{
//					*n = i;
//					*m = j;
//				}
//			}
//			j = (in->left_right == LEFT) ? j + 1 : j - 1;
//		}
//		i++;
//	}
//	return (enemy);
//}

int			fill_big(t_info *in)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 0;
	result = build_shield(in, &i, &j);
//	if (!result)
//		result = attack_enemy(in, &i, &j);
//	if (!result)
//		result = attack_between_shields(in, &i, &j);
	if (!result)
	{
		int tmp = in->map_high;
		in->map_high = in->enemy_high;
		result = attack(in, &i, &j);
		in->map_high = tmp;
	}
	if (!result)
		result = attack(in, &i, &j);
	ft_printf("%d %d\n", i, j);
	return (result);
}