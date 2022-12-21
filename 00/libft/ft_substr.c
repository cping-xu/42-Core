/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:31:29 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/06 14:30:46 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	if (!(s))
		return (NULL);
	while (s[j] != '\0')
		j++;
	if (j < start)
		len = 0;
	if (j < len)
		len = j - start;
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!(p))
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*#include <stdio.h>
int main()
{
	char	*s;

	s = ft_substr("BONJOUR LES HARICOTS !", 8, 14);
	printf("%s\n", s);
}*/
