/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2017/03/05 21:33:05 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect_four.h"

t_bool		com_easy(void)
{
	if (easy_verif(ID_COMPUTER) == 1)
		return (true);
	else if (easy_verif(ID_PLAYER) == 1)
	{
		P = 0;
		return (true);
	}
	else if (g_connect.difficulty == DIFFICULTY_EASY)
	{
		easy_random_pick();
		return (true);
	}
	return (false);
}

t_bool		com_medium(void)
{
	if (com_easy())
		return (true);
	else if (medium_verif(ID_COMPUTER) == 1)
		return (true);
	else if (medium_verif(ID_PLAYER) == 1)
	{
		P = 0;
		return (true);
	}
	medium_random_pick();
	return (false);
}

void		computer_turn(void)
{
	if (g_connect.difficulty == DIFFICULTY_EASY)
		com_easy();
	if (g_connect.difficulty == DIFFICULTY_MEDIUM)
		com_medium();
	g_connect.round++;
}
