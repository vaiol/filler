#include "main.h"

void	init_players(t_info *in)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 6)
	{
		get_next_line(FD, &line);
		free(line);
		i++;
	}
	get_next_line(FD, &line);
	in->p1 = ft_strsub(line, 14, ft_strlen(line) - 14);
	free(line);
	get_next_line(FD, &line);
	free(line);
	get_next_line(FD, &line);
	in->p2 = ft_strsub(line, 14, ft_strlen(line) - 14);
	free(line);
	in->map = NULL;
	in->move = NULL;
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