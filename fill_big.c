#include "fill.h"

static int	check_shield(t_info *in, int high)
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
				if (high + i == in->start_high)
					count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

static int	build_shield(t_info *in, int *n, int *m)
{
	int	i;
	int	j;
	int	shields;
	int c;

	shields = 0;
	i = in->start_high - 1;
	while (i >= 0)
	{
		j = (in->left_right == LEFT) ? 0 : in->map_width - 1;
		while (j < in->map_width && j >= 0)
		{
			if (put_piece(in, i, j))
			{
				if ((c = check_shield(in, i)) > shields && (shields = c))
				{
					*n = i;
					*m = j;
				}
			}
			j = (in->left_right == LEFT) ? j + 1 : j - 1;
		}
		i--;
	}
	return (shields);
}

int			fill_big(t_info *in)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 0;
	result = build_shield(in, &i, &j);
	if (!result)
		result = attack(in, &i, &j);
	ft_printf("%d %d\n", i, j);
	return (result);
}