/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:18 by cping-xu          #+#    #+#             */
/*   Updated: 2022/10/28 20:58:58 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c, int l);
int		ft_putstr(char *s, int l);
int		ft_putnbr(int n, int l);
int		ft_unsignednbr(unsigned int n, int l);
int		ft_putptr(unsigned long n, int l);
int		ft_putuphex(unsigned int n, int l);

#endif
