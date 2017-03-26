#include "main.h"

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
