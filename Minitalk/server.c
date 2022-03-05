/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:04:40 by ysachiko          #+#    #+#             */
/*   Updated: 2022/02/19 15:56:49 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	action(int sig, siginfo_t *siginfo, void *oldact)
{
	static int	bit;
	static int	g_char_chr;

	(void)oldact;
	g_char_chr |= (sig == SIGUSR2);
	if (++bit == 8)
	{
		bit = 0;
		if (!g_char_chr)
		{
			send_signal(siginfo->si_pid, SIGUSR2);
			return ;
		}
		ft_putchar_fd(g_char_chr, 1);
		g_char_chr = 0;
		send_signal(siginfo->si_pid, SIGUSR1);
	}
	else
		g_char_chr <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	ft_putchar_fd('\n', 1);
	sigemptyset(&s_sigaction.sa_mask);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &s_sigaction, 0) == -1
		|| sigaction(SIGUSR2, &s_sigaction, 0) == -1)
	{
		write(2, "Sigaction error\n", 16);
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
