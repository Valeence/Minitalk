/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 03:57:14 by vandre            #+#    #+#             */
/*   Updated: 2023/12/15 04:02:43 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char c)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = c;
	while (i > 0)
	{
		i--;
		temp_char = c >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}

int	main(int argc, char *argv[])
{
	const char	*str;
	int			i;

	if (argc != 3)
	{
		ft_printf("Usage:./client <pid> <message>\n");
		exit(0);
	}
	str = argv[2];
	i = 0;
	while (str[i])
		send_signal(ft_atoi(argv[1]), str[i++]);
	send_signal(ft_atoi(argv[1]), '\0');
	return (0);
}
