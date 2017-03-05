/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2017/03/05 10:46:05 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect_four.h"

void		setup_difficulty(void)
{
	ft_printf("1. Easy             (ALGORITHM)\n");
	ft_printf("2. Medium           (ALGORITHM)\n");
	ft_printf("3. Hard/Impossible  (Alpha-Beta Pruning w/ Optimizations)\n");
	while (true)
	{
		ft_printf("Select Difficulty (1,2,3): ");
		get_next_line(0, &g_connect.buffer);
		I = ft_atoi(g_connect.buffer);
		if (I <= 3 && I >= 1)
		{
			g_connect.difficulty = I;
			ft_printf("Selected Difficulty --> %i\n", I);
			break;
		}
	}
	if (g_connect.difficulty == DIFFICULTY_HARD && W > MAX_HARD_WIDTH)
		g_connect.error = 2;
	if (g_connect.difficulty == DIFFICULTY_HARD && (W * (H + 1) >
		MAX_HARD_BITS))
		g_connect.error = 2;
}

void		setup_game(void)
{
	setup_difficulty();
	srand(time(NULL));
	g_connect.round = 1;
	g_connect.first_turn = rand() % 2;
	g_connect.i = -1;
	g_connect.state = 1;
	g_connect.error = 0;
	g_connect.is_play = true;
	g_connect.draw = 0;
	g_connect.grid = malloc(sizeof(int *) * g_connect.input_w);
	while(++g_connect.i < g_connect.input_w)
	{
		g_connect.grid[g_connect.i] = malloc(sizeof(int) * g_connect.input_h);
		g_connect.j = -1;
		while (++g_connect.j < g_connect.input_h)
			g_connect.grid[g_connect.i][g_connect.j] = 0;
	}
	if (g_connect.first_turn)
		computer_turn();
}

void		end_game(void)
{
	g_connect.i = -1;
	while (++g_connect.i < g_connect.input_w)
		free(g_connect.grid[g_connect.i]);
	free(g_connect.grid);
	g_connect.is_play = false;
//	if (D_HARD_P1.init)
//		free(D_HARD_P1.column_order);
	ft_printf("GAME OVER\n");
}

void		game_loop(void)
{
	while(g_connect.is_play)
	{
		if (!g_connect.error)
			game_render();
		if (check_win(ID_PLAYER) || check_win(ID_COMPUTER))
			return ;
		if (g_connect.draw)
			break ;
		game_input();
		process_input();
		if (!g_connect.error)
			computer_turn();
	}
	ft_printf("MATCH DRAW\n");
}
