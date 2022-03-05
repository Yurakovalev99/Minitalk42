/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:11:17 by ysachiko          #+#    #+#             */
/*   Updated: 2022/02/19 14:09:21 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	mt_kill(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				send_signal(pid, SIGUSR2);
			else
				send_signal(pid, SIGUSR1);
			usleep(300);
		}
	}
	i = 8;
	while (i--)
	{
		send_signal(pid, SIGUSR1);
		usleep(300);
	}
}

static void	action(int sig)
{
	if (sig == SIGUSR2)
	{
		write(1, "Signal received\n", 16);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sigaction;

	if (argc != 3)
		return (1);
	s_sigaction.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sigaction.sa_mask);
	s_sigaction.sa_handler = action;
	if (sigaction(SIGUSR1, &s_sigaction, 0) == -1
		|| sigaction(SIGUSR2, &s_sigaction, 0) == -1)
	{
		write(2, "Sigaction error\n", 16);
		exit(1);
	}
	mt_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
