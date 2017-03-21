/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:42:28 by astepano          #+#    #+#             */
/*   Updated: 2017/03/10 17:42:44 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_H
# define PUT_H

# include <unistd.h>

size_t	g_count;
int		g_fd;

int		printed_count(void);
void	ft_write(const void *buf, size_t nbyte);
void	putstr(char const *s);

#endif
