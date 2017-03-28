#include "main.h"

char	*get_x(int nbr)
{
	char	color[120] = "\x1B[31m\0";
	char	res[100];

	ft_memset(res, 'X', 100);
	res[nbr] = '\0';
	strcat(color, res);
	strcat(color, "\x1B[0m\0");
	return (ft_strdup(color));
}

char	*get_o(int nbr)
{
	char	color[120] = "\x1B[34m\0";
	char	res[100];

	ft_memset(res, 'O', 100);
	res[nbr] = '\0';
	strcat(color, res);
	strcat(color, "\x1B[0m\0");
	return (ft_strdup(color));
}

char	*add(char *res, char chr, int count)
{
	char	*tmp;

	if (!res)
		res = ft_strdup("");
	if (chr == '.')
	{
		tmp = ft_strnew((size_t)count);
		ft_memset(tmp, ' ', (size_t)count);
		res = ft_strfjoin(res, tmp, BOTH);
	}
	else if (chr == 'x')
		res = ft_strfjoin(res, get_x(count), BOTH);
	else if (chr == 'o')
		res = ft_strfjoin(res, get_o(count), BOTH);
	return (res);
}

char	*change_line(t_info *in, const int i)
{
	int		c;
	int		j;
	char	chr;
	char	*res;

	res = NULL;
	j = 0;
	while (j < in->map_width)
	{
		c = 1;
		chr = (char)ft_tolower(in->map[i][j]);
		while (chr == ft_tolower(in->map[i][j + c]))
			c++;
		res = add(res, chr, c);
		j += c;
	}
	res = ft_strfjoin(res, "\n", FIRST);
	return (res);
}

void	print_map(t_info *in)
{
	char	*move;
	char	*delim;
	int		i;

	delim = ft_strdup("");
	i = 0;
	while (i < in->map_high)
	{
		delim = ft_strfjoin(delim, change_line(in, i), BOTH);
		i++;
	}
	move = ft_strfjoin("\x1B[33m\0", in->move, NONE);
	move = ft_strfjoin(move, "\x1B[0m\0", FIRST);
	move = ft_strfjoin(delim, move, BOTH);
	move = ft_strfjoin(move, "\n", FIRST);
	setbuf(stdout, NULL);
	system("clear");
	printf("%s", move);
	fflush(stdout);
}