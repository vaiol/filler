#include "filler.h"

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
	free(line);
}

void	init_map(t_info *in)
{
	int i;
	char *line;

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

	in->start_high = 0;
	while (in->start_high < in->map_high)
	{
		j = 0;
		while (j < in->map_width)
		{
			if (ft_tolower(in->map[in->start_high ][j]) == in->player)
			{
				if (in->start_high  < (in->map_high / 2))
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
		in->start_high++;
	}
}
