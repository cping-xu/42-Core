/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:29:49 by cping-xu          #+#    #+#             */
/*   Updated: 2022/11/30 14:29:49 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	printerror(char **a)
{
	if (errorhandle(a) == 1)
		write(2, "Error\n", 6);
	return (0);
}

void	free_used(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
}

int	main(int ac, char **av)
{
	char	**stack_a;
	char	**stack_b;
	char	*store;
	int		i;
	int		k;

	i = aclen(av);
	k = arraylen(av);
	if (ac == 1)
		return (0);
	store = ft_strdup(av, k);
	stack_a = ft_split(store, ' ');
	if (errorhandle(stack_a) == 2)
		return (0);
	if (errorhandle(stack_a) == 1)
		return (printerror(stack_a));
	stack_b = ft_calloc(i + 1, sizeof(char *));
	if (i < 6)
		return (swapless(stack_a, stack_b, i));
	free_used(stack_a);
	stack_a = ft_set_order(store);
	swap(stack_a, stack_b, i);
	free(stack_b);
}
