/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:02:39 by astepano          #+#    #+#             */
/*   Updated: 2017/03/29 20:02:40 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
