#include "filler.h"

void	init_symbols(t_info *in)
{
	char	*line;
	int		i;

	get_next_line(1, &line);
	i = ft_atoi(line + 10);
	if (i == 1)
	{
		in->p_symbol = 'o';
		in->o_symbol = 'x';
	}
	else
	{
		in->p_symbol = 'x';
		in->o_symbol = 'o';
	}
	free(line);
}

void	init_map(t_info *in)
{
	int i;
	int width;
	char *line;

	get_next_line(1, &line);
	i = 8;
	in->map_high = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	width = ft_atoi(line + i);
	get_next_line(1, &line);
	free(line);
	in->map = (char **)malloc(sizeof(char *) * (in->map_high + 1));
	i = 0;
	while (i < in->map_high)
	{
		get_next_line(1, &line);
		in->map[i] = ft_strsub(line, 4, (size_t)width);
		free(line);
		i++;
	}
	in->map[i] = NULL;
	free(line);
}
