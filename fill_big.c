/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:45:36 by astepano          #+#    #+#             */
/*   Updated: 2017/03/29 19:45:37 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

static int	check_shield(t_info *in, int high, int width, int *c)
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
				if ((high + i == in->player_high || high + i == in->enemy_high)
					&& ft_tolower(in->map[i + high][j + width]) != in->player)
					count++;
			}
			j++;
		}
		i++;
	}
	if (count > *c && (*c = count))
		return (1);
	return (0);
}

static int	build_shield(t_info *in, int *n, int *m)
{
	int	i;
	int	j;
	int	shields;

	shields = 0;
	i = -100;
	while (i <= in->map_high)
	{
		j = (in->left_right == LEFT) ? -100 : in->map_width - 1;
		while (j < in->map_width && j >= -100)
		{
			if (put_piece(in, i, j))
			{
				if (check_shield(in, i, j, &shields))
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

static void	check_direction(t_info *in)
{
	int e;
	int p;
	int	i;

	if (in->changed)
		return ;
	p = 0;
	e = 0;
	i = 0;
	while (i < in->map_width)
	{
		if (ft_tolower(in->map[in->enemy_high][i]) == in->player)
			p = 1;
		if (ft_tolower(in->map[in->player_high][i]) == in->enemy)
			e = 1;
		i++;
	}
	if ((p && e))
	{
		in->up_down = (in->up_down == DOWN) ? UP : DOWN;
		in->changed = 1;
	}
}

static int	two_shields(t_info *in)
{
	int	i;

	i = 0;
	while (i < in->map_width)
	{
		if (ft_tolower(in->map[in->player_high][i]) != in->player)
			return (0);
		if (ft_tolower(in->map[in->enemy_high][i]) != in->player)
			return (0);
		i++;
	}
	return (1);
}

int			fill_big(t_info *in)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 0;
	result = build_shield(in, &i, &j);
	if (!result && two_shields(in))
		result = attack_between(in, &i, &j);
	if (!result)
		result = attack(in, &i, &j);
	check_direction(in);
	ft_printf("%d %d\n", i, j);
	return (result);
}
