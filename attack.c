/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:57:28 by astepano          #+#    #+#             */
/*   Updated: 2017/03/29 19:57:29 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

static int	check_between(t_info *in, const int i)
{
	int	k;
	int l;

	k = 0;
	while (in->piece[k])
	{
		l = 0;
		while (in->piece[k][l])
		{
			if (in->piece[k][l] == '*')
			{
				if (in->up_down == UP
					&& (k + i < in->enemy_high || k + i > in->player_high))
					return (0);
				if (in->up_down == DOWN
					&& (k + i > in->enemy_high || k + i < in->player_high))
					return (0);
			}
			l++;
		}
		k++;
	}
	return (1);
}

int			attack_between(t_info *in, int *n, int *m)
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
			if (put_piece(in, i, j) && check_between(in, i))
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

int			put_piece(t_info *in, const int i, const int j)
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

int			attack(t_info *in, int *n, int *m)
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
