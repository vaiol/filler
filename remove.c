#include "fill.h"

void	remove_map(t_info *in)
{
	int	i;

	if (in->map == NULL)
		return ;
	i = 0;
	while (in->map[i])
		free(in->map[i++]);
	free(in->map);
	in->map = NULL;
}

void	remove_piece(t_info *in)
{
	int	i;

	if (in->piece == NULL)
		return ;
	i = 0;
	while (in->piece[i])
		free(in->piece[i++]);
	free(in->piece);
	in->piece = NULL;
}
