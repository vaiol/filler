#include "main.h"

void	finish(int p1, int p2, t_info *in)
{
	if (p1 > p2)
		ft_printf("{blue}%s{eoc} {yellow}WIN!!!!!!!!!!!!!{eoc}\n", in->p1);
	else if (p2 > p1)
		ft_printf("{red}%s{eoc} {yellow}WIN!!!!!!!!!!!!!{eoc}\n", in->p2);
	else
		ft_printf("{yellow}DRAW... Try again!{eoc}\n");
}

void	update_map(t_info *in)
{
	int		j;
	int		i;
	char	*line;
	char	*tmp;

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

void	skip_piece(char *line)
{
	int		i;
	int		high;

	if (!line)
		get_next_line(FD, &line);
	i = 6;
	high = ft_atoi(line + i);
	free(line);
	i = 0;
	while (i < high)
	{
		get_next_line(FD, &line);
		free(line);
		i++;
	}
}

int isfinish(t_info *in)
{
	char	*line;
	int		p1;
	int		p2;

	get_next_line(FD, &line);
	if (in->move)
		free(in->move - 5);
	in->move = line + 5;
	get_next_line(FD, &line);
	if (line[0] == '=' && line[1] == '=')
	{
		p1 = ft_atoi(line + 10);
		free(line);
		get_next_line(FD, &line);
		p2 = ft_atoi(line + 10);
		free(line);
		finish(p1, p2, in);
		return (0);
	} else if (line[0] == 'P' && line[1] == 'i')
	{
		skip_piece(line);
		return (2);
	}
	free(line);
	return (1);
}

int	main(void)
{
	int		finish;
	t_info	*in;

	in = (t_info *)malloc(sizeof(t_info));
	init_players(in);
	init_map(in);
	skip_piece(NULL);
	while ((finish = isfinish(in)))
	{
		if (finish == 1)
		{
			update_map(in);
			skip_piece(NULL);
			print_map(in);
		}
	}
	remove_map(in);
	free(in->p1);
	free(in->p2);
	free(in);
	return (0);
}