/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 03:57:14 by vandre            #+#    #+#             */
/*   Updated: 2023/12/13 04:07:57 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(int pid, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if (str[i] & (1 << j))
			{
				printf("1");
				kill(pid, SIGUSR1);
			}
			else
			{	
				printf("0");
				kill(pid, SIGUSR2);
			}
		}
	}

}

void	signal_handler_client(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal == SIGUSR1)
		g_a = 1;
}

int	main(int ac, char **av)
{
	struct sigaction	act;

	act.sa_sigaction = signal_handler_client;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	if (ac != 3)
		return (printf("Usage: ./client [PID] [message]\n"));
	send_msg(ft_atoi(av[1]), av[2]);
}
