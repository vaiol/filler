#include "filler.h"

int	main(void)
{
	t_info	*in;

	in = (t_info *)malloc(sizeof(t_info));
	init_symbols(in);
	init_map(in);
	init_direction(in);
	update_piece(in);
	while (fill(in))
	{
		update_map(in);
		update_piece(in);
	}
	remove_map(in);
	remove_piece(in);
	free(in);
	return (0);
}