/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:07:02 by abassibe          #+#    #+#             */
/*   Updated: 2017/03/04 18:07:08 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect_four.h"

void	medium_random_pick(void)
{
	int		random;

	random = rand() % g_connect.input_w;
	if (random == 0)
		random++;
	g_connect.insert_c = random + 1;
	player_stack(ID_COMPUTER);
}
