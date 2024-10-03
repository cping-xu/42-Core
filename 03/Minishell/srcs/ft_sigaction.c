/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigaction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:00:56 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/04/04 15:20:10 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int signo)
{
	ft_putendl_fd("", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
