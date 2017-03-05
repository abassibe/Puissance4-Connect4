/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2017/03/05 18:37:08 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect_four.h"

void		com_hard(void)
{
	int		result;

	if (!D_HARD_P1.init)
	{
result = 0;
	}
}

void		com_medium(void)
{

}

void		com_easy(void)
{
	if (easy_verif(ID_COMPUTER) == 1)
		return ;
	else if (easy_verif(ID_PLAYER) == 1)
	{
		P = 0;
		return ;
	}
	else
		easy_random_pick();
}

void		computer_turn(void)
{
	if (g_connect.difficulty == DIFFICULTY_EASY)
		com_easy();
	if (g_connect.difficulty == DIFFICULTY_MEDIUM)
		com_medium();
	if (g_connect.difficulty == DIFFICULTY_HARD)
		com_hard();
}
