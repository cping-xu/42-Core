/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:26:49 by cping-xu          #+#    #+#             */
/*   Updated: 2023/04/04 18:48:08 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_remove_in_out_from_list(char ***list, int l)
{
	int		i;
	int		j;
	int		c;
	char	**temp;

	c = 0;
	i = 0;
	while ((*list)[i])
		i++;
	if (i == l)
		i++;
	temp = malloc(sizeof(char *) * (i - l + 1));
	i = 0;
	j = 0;
	while ((*list)[i])
	{
		if (!ft_strncmp((*list)[i], "<", 2))
		{
			free((*list)[i]);
			i++;
			if ((*list)[i] && ft_strncmp((*list)[i], ">", 2))
				free((*list)[i++]);
			c++;
		}
		else if (!ft_strncmp((*list)[i], ">", 2))
		{
			free((*list)[i]);
			i++;
			if ((*list)[i] && ft_strncmp((*list)[i], "<", 2))
				free((*list)[i++]);
			c++;
		}
		else if (!ft_strncmp((*list)[i], ">>", 3))
		{
			free((*list)[i]);
			i++;
			if ((*list)[i])
				free((*list)[i++]);
			c++;
		}
		else if (!ft_strncmp((*list)[i], "<<", 3))
		{
			free((*list)[i]);
			i++;
			if ((*list)[i])
				free((*list)[i++]);
			c++;
		}
		else
		{
			temp[j++] = ft_strdup((*list)[i]);
			free((*list)[i++]);
		}
	}
	if (j == 0 && c > 0)
		temp[j++] = ft_strdup("cat");
	temp[j] = NULL;
	return (temp);
}

void	ft_handle_in_out_file(t_mini *mini, int n)
{
	int		i;
	int		l;
	int		fd;
	char	***list;

	i = 0;
	l = 0;
	list = &mini->pipe_line[n];
	while ((*list)[i])
	{
		if (!ft_strncmp((*list)[i], "<", 2))
		{
			l++;
			if ((*list)[i + 1])
			{
				l++;
				fd = open((*list)[i + 1], O_RDONLY);
				if (fd == -1)
				{
					perror("Infile");
					exit(0);
				}
				dup2(fd, 0);
				close(fd);
			}
		}
		else if (!ft_strncmp((*list)[i], ">", 2))
		{
			l++;
			if ((*list)[i + 1])
			{
				l++;
				fd = open((*list)[i + 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
				dup2(fd, 1);
				close(fd);
			}
		}
		else if (!ft_strncmp((*list)[i], ">>", 3))
		{
			l++;
			if ((*list)[i + 1])
			{
				l++;
				fd = open((*list)[i + 1], O_APPEND | O_CREAT | O_RDWR, 0644);
				if (fd == -1)
					perror("Outfile");
				dup2(fd, 1);
				close(fd);
			}
		}
		if (!ft_strncmp((*list)[i], "<<", 3))
		{
			l++;
			if ((*list)[i + 1])
			{
				dup2(mini->here_fd[mini->here_id][0], 0);
				close(mini->here_fd[mini->here_id][0]);
				close(mini->here_fd[mini->here_id][1]);
				mini->here_id++;
			}
			else
				perror("parse");
		}
		i++;
	}
	*list = ft_remove_in_out_from_list(list, l);
}
