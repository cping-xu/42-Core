/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:30:35 by cping-xu          #+#    #+#             */
/*   Updated: 2022/12/07 12:38:54 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

int			ft_intcmp(char *s1, char *s2);
int			checknum(char **str);
int			checkplace(char **s1);
int			checkac(char **str);
int			checkint(char **str);
int			errorhandle(char **str);
void		*ft_calloc(size_t count, size_t size);
char		**ft_split(char *s, char c);
long long	ft_atoi(const char *str);
char		*ft_itoa(int n);
int			aclen(char **str);
int			arraylen(char **str);
char		*ft_strdup(char **str, int k);
void		swaptwo(char **a);
void		swapthree(char **str);
int			swapless(char **a, char **b, int num);
void		swapmore(char **a, char **b, int num);
void		pushmin(char **a);
void		swap(char **a, char **b, int num);
void		rra(char **str);
void		rrb(char **str);
void		ra(char **str);
void		rb(char **str);
void		sa(char	**str);
void		sb(char	**str);
void		pa(char **a, char **b);
void		pb(char **a, char **b);
char		**ft_set_order(char *str);
void		free_used(char **a);
int			findsmall(char **a, char **b, int t, int *p);
void		pushmax(char **a, char **b);

#endif