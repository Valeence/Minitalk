/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 03:57:20 by vandre            #+#    #+#             */
/*   Updated: 2023/12/13 19:37:00 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler_client(int signal, siginfo_t *info, void *context)
{
	int		bit_index;
	char	c;

	bit_index = 0;
	c = 0;
	(void)context;
	if (signal == SIGUSR1)
		c = (c << 1) | 1;
	else if (signal == SIGUSR2)
		c <<= 1;
	bit_index++;
	if (bit_index == 8)
	{
		ft_printf("%c", c);
		bit_index = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("%d\n", getpid());

	act.sa_sigaction = signal_handler_client;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	while (1)
		pause();
	return (0);
}
