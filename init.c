/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:46:06 by astepano          #+#    #+#             */
/*   Updated: 2017/03/29 19:46:08 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

void	init_symbols(t_info *in)
{
	char	*line;
	int		i;

	get_next_line(FD, &line);
	i = ft_atoi(line + 10);
	if (i == 1)
	{
		in->player = 'o';
		in->enemy = 'x';
	}
	else
	{
		in->player = 'x';
		in->enemy = 'o';
	}
	in->piece = NULL;
	in->map = NULL;
	in->changed = 0;
	free(line);
}

void	init_map(t_info *in)
{
	int		i;
	char	*line;

	i = 8;
	get_next_line(FD, &line);
	in->map_high = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	in->map_width = ft_atoi(line + i);
	free(line);
	get_next_line(FD, &line);
	free(line);
	in->map = (char **)malloc(sizeof(char *) * (in->map_high + 1));
	i = 0;
	while (i < in->map_high)
	{
		get_next_line(FD, &line);
		in->map[i] = ft_strsub(line, 4, (size_t)in->map_width);
		free(line);
		i++;
	}
	in->map[i] = NULL;
}

void	init_direction(t_info *in)
{
	int	j;
	int i;

	i = 0;
	while (i < in->map_high)
	{
		j = 0;
		while (j < in->map_width)
		{
			if (ft_tolower(in->map[i][j]) == in->player)
			{
				if (i < (in->map_high / 2))
					in->up_down = DOWN;
				else
					in->up_down = UP;
				if (j < (in->map_width / 2))
					in->left_right = RIGHT;
				else
					in->left_right = LEFT;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_highs(t_info *in)
{
	int	j;
	int i;

	i = 0;
	while (i < in->map_high)
	{
		j = 0;
		while (j < in->map_width)
		{
			if (ft_tolower(in->map[i][j]) == in->player)
				in->player_high = i;
			if (ft_tolower(in->map[i][j]) == in->enemy)
				in->enemy_high = i;
			j++;
		}
		i++;
	}
	if (in->up_down == DOWN)
		in->enemy_high += 3;
	else
		in->enemy_high -= 3;
}
