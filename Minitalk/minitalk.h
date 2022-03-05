/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:11:56 by ysachiko          #+#    #+#             */
/*   Updated: 2022/02/19 15:56:45 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

void		ft_putnbr(int n);
void		ft_putchar_fd(char c, int fd);
size_t		ft_strlen(char *str);
int			ft_atoi(const char *str);
void		send_signal(int pid, int signum);

#endif
