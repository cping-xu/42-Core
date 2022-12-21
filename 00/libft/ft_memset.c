/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:37:43 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/12 15:26:45 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>
#include <string.h>
int main () 
{
   char str[] = "qwertyuioqwertyuio";
   printf("%s\n",ft_memset(str,'$',7));
   printf("%s\n",memset(str, '$', 7));
}*/
