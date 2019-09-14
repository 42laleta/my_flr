/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_draw_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:43:07 by laleta            #+#    #+#             */
/*   Updated: 2019/09/14 16:17:47 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flr_visual.h"

static void			ft_free_shape(char ***shape)
{
	char	**tmp;

	tmp = *shape;
	while (**shape)
	{
		free(**shape);
		++*shape;
	}
	free(tmp);
}

static void			ft_get_shape(t_sfml *sfml, int cnt)
{
	char		**shape;
	int32_t		i;

	if (!(shape = (char **)malloc(sizeof(*shape) * (cnt + 1))))
		return ;
	shape[cnt] = NULL;
	i = 0;
	while (i < cnt && get_next_line(sfml->fd, &shape[i]) && shape[i])
		++i;
	ft_set_shape(sfml, shape);
	if (sfml->map_vm == 0 && (g_state & FLR_SOUN))
	{
		sfSound_setBuffer(sfml->sound, sfml->sound_buf_er);
		sfSound_play(sfml->sound);
	}
	ft_free_shape(&shape);
}

static inline void	ft_set_flag(t_sfml *sfml)
{
	char	c;
	int32_t	flags;

	if (sfml->map_vm != -1 || !read(g_fdmap, &c, 1))
	{
		++sfml->map_vm;
		sfml->fd = g_fdadp;
		g_state |= FLR_LOSE;
		flags = fcntl(g_fdadp, F_GETFL, 0);
		flags &= ~O_NONBLOCK;
		fcntl(g_fdadp, F_SETFL, flags);
	}
	else if (sfml->fd != g_fdadp)
	{
		++sfml->map_pl;
		if (read(g_fdadp, &c, 1) == 1)
			g_state |= FLR_ADP;
		else
			g_state &= ~FLR_ADP;
	}
}

static inline void	ft_read_del_adp(t_sfml *sfml)
{
	int32_t	ret;
	char	*s;
	char	one;

	read(g_fdvm, &one, 1);
	if (sfml->map_pl > 80 && sfml->fd != g_fdadp && (g_state & FLR_READ) &&
															(g_state & FLR_ADP))
	{
		g_state &= ~FLR_READ;
		if (sfml->cell_cnt > 9000)
			sleep(1);
		while ((ret = get_next_line(g_fdadp, &s)) && (*s != '+'))
		{
			if (ret > 0)
				free(s);
		}
		if (sfml->cell_cnt > 9000)
			sleep(1);
		while (one != '-' && (ret = get_next_line(g_fdadp, &s)) && (*s != '+'))
		{
			if (ret > 0)
				free(s);
		}
	}
}

void				ft_draw_shape(t_sfml *sfml)
{
	char	*s;
	int32_t	ret;

	ft_draw_header(sfml);
	if (g_state & FLR_FIN)
		return ;
	ft_set_flag(sfml);
	ft_read_del_adp(sfml);
	while ((ret = get_next_line(sfml->fd, &s)) && (*s != '+'))
	{
		if (ret > 0)
			free(s);
	}
	if (ret > 0)
	{
		ft_get_shape(sfml, sfml->height);
		free(s);
	}
	else
		g_state |= FLR_FIN;
	return ;
}
