/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:07:25 by dainoue           #+#    #+#             */
/*   Updated: 2022/02/21 03:46:28 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/minitalk.h"
#include "../includes/client.h"

void	awk_receiver(int signal)
{
	if (signal == SIGUSR1)
		printf("> The transmission processing is normally finished\n");
	exit(0);
}

void	put_error(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd(strerror(errno), 1);
	write(1, "\n", 1);
	exit(1);
}

void	send_char(pid_t server_pid, char c)
{
	int	bit;
	int	error;

	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
			error = kill(server_pid, SIGUSR1);
		else
			error = kill(server_pid, SIGUSR2);
		if (error == -1)
			put_error("> invalid pid : ");
		bit -= 1;
		usleep(50);
	}
}

void	send_message(pid_t server_pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, (char)4);
}

int	main(int argc, char **argv)
{
	char	*message;
	pid_t	server_pid;

	if (argc <= 2)
	{
		ft_putstr_fd("Error.\n", 1);
		return (0);
	}
	server_pid = (pid_t)ft_atoi(argv[1]);
	message = argv[2];
	send_message(server_pid, message);
	return (0);
}
