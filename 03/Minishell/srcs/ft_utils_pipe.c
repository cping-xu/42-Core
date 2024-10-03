/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:28:04 by cping-xu          #+#    #+#             */
/*   Updated: 2023/04/04 18:28:29 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_parent_cmd(t_mini *mini)
{
	int		i;
	char	**list;

	i = 0;
	list = mini->pipe_line[mini->pipe_count - 1];
	while (list[i])
	{
		if (!ft_strncmp(list[i], "exit", 5))
			return (1);
		else if (!ft_strncmp(list[i], "cd", 3))
			return (1);
		else if (!ft_strncmp(list[i], "export", 7))
			return (1);
		else if (!ft_strncmp(list[i], "unset", 6))
			return (1);
		i++;
	}
	return (0);
}

void	ft_parent_cmd(t_mini	*mini, char **line)
{
	char	*str;

	str = line[0];
	if (!str)
		exit(0);
	else if (!ft_strncmp(str, "exit", 5))
		exit(0);
	else if (!ft_strncmp(str, "cd", 3))
		ft_cd(mini, mini->env, line);
	else if (!ft_strncmp(str, "export", 7))
		ft_export(mini, line);
	else if (!ft_strncmp(str, "unset", 6))
		ft_unset(mini, line);
}

void	ft_child_cmd(t_mini *mini, int *i)
{
	while (mini->pipe_line[(*i)])
	{
		mini->pid2 = fork();
		if (mini->pid2 == 0)
		{
			if ((*i) > 0)
			{
				close(mini->fd[(*i) - 1][1]);
				dup2(mini->fd[(*i) - 1][0], 0);
			}
			if (mini->pipe_line[(*i) + 1])
				dup2(mini->fd[(*i)][1], 1);
			else
				dup2(1, 1);
			ft_handle_in_out_file(mini, (*i));
			ft_cmd(mini, mini->pipe_line[(*i)]);
		}
		(*i)++;
	}
}
