/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:19:59 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/07 15:32:27 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	char	*s;

	s = (char *)str;
	if (to_find[0] == '\0')
		return (s);
	i = 0;
	while (i < n && s[i] != '\0')
	{
		j = 0;
		while (s[i + j] == to_find[j] && i + j < n)
		{
			j++;
			if (to_find[j] == '\0')
			{
				return (&s[i]);
			}
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>
int main(void)
{
	char str[] = "aaabcabcd";
	char to[] = "cd";

	printf("%s", ft_strnstr(str, to, 8));
}*/
