/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:45:14 by astepano          #+#    #+#             */
/*   Updated: 2017/03/29 19:45:16 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

int		fill(t_info *in)
{
	if (in->map_high > 50)
		return (fill_big(in));
	return (fill_small(in));
}

int		main(void)
{
	t_info	*in;

	in = (t_info *)malloc(sizeof(t_info));
	init_symbols(in);
	init_map(in);
	init_direction(in);
	init_highs(in);
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
