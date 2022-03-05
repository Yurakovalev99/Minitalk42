/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:51:52 by ysachiko          #+#    #+#             */
/*   Updated: 2022/02/19 15:56:53 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	char	a;

	if (n < 0)
		write(1, "-", sizeof(char));
	while (n / 10 != 0)
	{
		if (n > 0)
			n = -n;
		ft_putnbr((-1) * (n / 10));
		n = (-1) * n % 10;
	}
	if (n < 0)
		n = -n;
	a = n + '0';
	write(1, &a, sizeof(char));
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

int	ft_atoi(const char *str)
{
	size_t		i;
	long long	j;
	short		sign;

	i = 0;
	j = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (j * 10 + (sign * (str[i] - '0')) < j && sign > 0)
			return (-1);
		if (j * 10 + (sign * (str[i] - '0')) > j && sign < 0)
			return (0);
		j = j * 10 + (sign * (str[i] - '0'));
		i++;
	}
	return (j);
}

void	send_signal(int pid, int signum)
{
	if (kill(pid, signum))
	{
		write(2, "Signal send error\n", 18);
		exit(EXIT_FAILURE);
	}
}
