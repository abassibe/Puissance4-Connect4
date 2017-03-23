/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:02:35 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/05 21:35:42 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect_four.h"

int		medium_count_connect_v(t_easy *compar, int p, int j, int i)
{
	compar->count2 = 0;
	compar->count = 0;
	compar->pos_i = 0;
	compar->pos_j = 0;
	while (++j < g_connect.input_h - 2)
	{
		if (g_connect.grid[i][j] == p)
			compar->count2++;
		if (g_connect.grid[i][j + 1] == p)
			compar->count2++;
		if (compar->count < compar->count2)
		{
			compar->count = compar->count2;
			compar->pos_j = j;
			compar->pos_i = i;
		}
		if (compar->count2 == 2)
			return (medium_counter_win_v(compar));
		compar->count2 = 0;
	}
	return (0);
}

int		medium_count_connect_h(t_easy *compar, int p, int j, int i)
{
	compar->count2 = 0;
	compar->count = 0;
	compar->pos_i = 0;
	compar->pos_j = 0;
	while (++i < g_connect.input_w - 2)
	{
		if (g_connect.grid[i][j] == p)
			compar->count2++;
		if (g_connect.grid[i + 1][j] == p)
			compar->count2++;
		if (compar->count < compar->count2)
		{
			compar->count = compar->count2;
			compar->pos_i = i;
			compar->pos_j = j;
		}
		if (compar->count2 == 2)
			return (medium_counter_win_h(compar));
		compar->count2 = 0;
	}
	return (0);
}

int		medium_count_connect_diag_g(t_easy *compar, int p, int j, int i)
{
	compar->count2 = 0;
	compar->count = 0;
	compar->pos_i = 0;
	compar->pos_j = 0;
	while (++j < g_connect.input_h - 2)
	{
		if (g_connect.grid[i][j] == p)
			compar->count2++;
		if (g_connect.grid[i + 1][j + 1] == p)
			compar->count2++;
		if (compar->count < compar->count2)
		{
			compar->count = compar->count2;
			compar->pos_i = j;
			compar->pos_j = i;
		}
		if (compar->count2 == 2)
			return (medium_counter_win_g(compar));
		compar->count2 = 0;
	}
	return (0);
}

int		medium_count_connect_diag_d(t_easy *compar, int p, int j, int i)
{
	compar->count2 = 0;
	compar->count = 0;
	compar->pos_i = 0;
	compar->pos_j = 0;
	while (++j < g_connect.input_h)
	{
		if (g_connect.grid[i][j] == p)
			compar->count2++;
		if (g_connect.grid[i + 1][j - 1] == p)
			compar->count2++;
		if (compar->count < compar->count2)
		{
			compar->count = compar->count2;
			compar->pos_i = j;
			compar->pos_j = i;
		}
		if (compar->count2 == 2)
			return (medium_counter_win_d(compar));
		compar->count2 = 0;
	}
	return (0);
}

t_easy	medium_compar(t_easy *compar, int p)
{
	J = -1;
	I = -1;
	while (++J < g_connect.input_h)
		if ((P = medium_count_connect_h(compar, p, J, I)) == 1)
			return (*compar);
	I = -1;
	J = -1;
	while (++I < g_connect.input_w)
		if ((P = medium_count_connect_v(compar, p, J, I)) == 1)
			return (*compar);
	I = -1;
	J = -1;
	while (++I < g_connect.input_w - 2)
		if ((P = medium_count_connect_diag_g(compar, p, J, I)) == 1)
			return (*compar);
	I = -1;
	J = 1;
	while (++I < g_connect.input_w - 2)
		if ((P = medium_count_connect_diag_d(compar, p, J, I)) == 1)
			return (*compar);
	return (*compar);
}
