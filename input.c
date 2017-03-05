/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2017/03/05 10:46:22 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect_four.h"

void			game_input(void)
{
	if (g_connect.state == STATE_PLAY)
		ft_printf("Input Insertion Column (%i-%i): ", 1, g_connect.input_w);
	get_next_line(0, &g_connect.buffer);
}

void			player_stack(int id)
{
	g_connect.j = -1;
	while (++g_connect.j < g_connect.input_h)
	{
		if (g_connect.grid[g_connect.insert_c - 1][g_connect.j] > 0)
		{
			if (g_connect.j - 1 < 0)
			{
				g_connect.insert_c = -1;
				g_connect.error = ERROR_INPUT;
				return ;
			}
			g_connect.grid[g_connect.insert_c - 1][g_connect.j - 1] = id;
			return ;
		}
	}
	g_connect.grid[g_connect.insert_c - 1][g_connect.input_h - 1] = id;
}

void			process_input(void)
{
	g_connect.error = 0;
	if (g_connect.state == STATE_PLAY)
	{
		g_connect.insert_c = ft_atoi(g_connect.buffer);
		if (g_connect.insert_c < 1 ||
			g_connect.insert_c > g_connect.input_w)
		{
			g_connect.insert_c = -1;
			g_connect.error = ERROR_INPUT;
		}
		else
		{
			player_stack(ID_PLAYER);
//			hard_play(&D_HARD_P1, g_connect.insert_c);
		}
	}
}
