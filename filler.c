#include "filler.h"

int		put(t_info *in, const int i, const int j)
{
	int	count;
	int	k;
	int l;

	count = 0;
	k = 0;
	while (in->piece[k])
	{
		l = 0;
		if (!in->map[i + k])
			return (0);
		while (in->piece[k][l])
		{
			if (!in->map[i + k][j + l] || in->map[i + k][j + l] == in->o_symbol)
				return (0);
			if (in->piece[k][l] == '*' && in->map[i + k][j + l] == in->p_symbol)
				count++;
			if (count > 1)
				return (0);
			l++;
		}
		k++;
	}
	return (1);
}

int		run(t_info *in)
{
	int	i;
	int	j;

	i = 0;
	while (in->map[i])
	{
		j = 0;
		while (in->map[i][j])
		{
			if (put(in, i, j))
			{
				printf("%d %d\n", i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main(void)
{

	t_info	*in;

	in = (t_info *)malloc(sizeof(t_info));
	init_symbols(in);
	init_map(in);
	update_piece(in);
	while (run(in))
	{
		update_map(in);
		update_piece(in);
	}
	remove_map(in);
	remove_piece(in);
	free(in);
	return (0);
}