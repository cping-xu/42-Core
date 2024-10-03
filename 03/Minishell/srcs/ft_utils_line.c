/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:35:10 by cping-xu          #+#    #+#             */
/*   Updated: 2023/04/04 18:39:03 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_line_dup(char *s)
{
	char	*dest;
	int		i;
	int		j;
	int		c;

	i = 0;
	j = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '|' || s[i] == '<' || s[i] == '>')
			c += 2;
		i++;
	}
	dest = (char *) malloc (sizeof(char) * (i + c + 1));
	i = 0;
	if (!dest)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == 39)
		{
			dest[j++] = s[i++];
			while (s[i] && s[i] != 39)
			{
				if (ft_check_quote(s + i, 39))
					break ;
				dest[j++] = s[i++];
			}
		}
		else if (s[i] == 34)
		{
			dest[j++] = s[i++];
			while (s[i] && s[i] != 34)
			{
				if (ft_check_quote(s + i, 34))
					break ;
				dest[j++] = s[i++];
			}
		}
		if (s[i] == '|')
		{
			dest[j++] = ' ';
			dest[j++] = '|';
			dest[j++] = ' ';
			i++;
		}
		else if (s[i] == '<' && s[i + 1] == '<')
		{
			dest[j++] = ' ';
			dest[j++] = '<';
			dest[j++] = '<';
			dest[j++] = ' ';
			i += 2;
		}
		else if (s[i] == '>' && s[i + 1] == '>')
		{
			dest[j++] = ' ';
			dest[j++] = '>';
			dest[j++] = '>';
			dest[j++] = ' ';
			i += 2;
		}
		else if (s[i] == '<')
		{
			dest[j++] = ' ';
			dest[j++] = '<';
			dest[j++] = ' ';
			i++;
		}
		else if (s[i] == '>')
		{
			dest[j++] = ' ';
			dest[j++] = '>';
			dest[j++] = ' ';
			i++;
		}
		else
			dest[j++] = s[i++];
	}
	dest[j] = '\0';
	return (dest);
}
