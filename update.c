#include "fill.h"

void	update_map(t_info *in)
{
	int		j;
	int		i;
	char	*line;
	char	*tmp;

	get_next_line(FD, &line);
	free(line);
	get_next_line(FD, &line);
	free(line);
	i = 0;
	while (i < in->map_high)
	{
		get_next_line(FD, &tmp);
		line = tmp + 4;
		j = 0;
		while (j < in->map_width)
		{
			in->map[i][j] = line[j];
			j++;
		}
		free(tmp);
		i++;
	}
}

void	update_piece(t_info *in)
{
	int		i;
	int		high;
	int		len;
	char	*line;

	get_next_line(FD, &line);
	i = 6;
	high = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	len = ft_atoi(line + i);
	free(line);
	remove_piece(in);
	in->piece = (char **)malloc(sizeof(char *) * (high + 1));
	i = 0;
	while (i < high)
	{
		get_next_line(FD, &line);
		in->piece[i] = ft_strsub(line, 0, (size_t)len);
		free(line);
		i++;
	}
	in->piece[i] = NULL;
}