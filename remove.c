/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:46:15 by astepano          #+#    #+#             */
/*   Updated: 2017/03/29 19:46:16 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
