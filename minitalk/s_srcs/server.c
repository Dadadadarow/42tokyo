/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:18:28 by dainoue           #+#    #+#             */
/*   Updated: 2022/02/21 04:21:14 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"

void	signal_action(int signal, siginfo_t *info, void *message)
{
	static unsigned char	buf[1000000];
	static int				i;
	static int				bit_count;

	(void)info;
	(void)message;
	if (signal == SIGUSR1)
		buf[i] |= (1 << (7 - bit_count));
	else
		buf[i] &= ~(1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		bit_count = 0;
		if (buf[i] == (char)4)
		{
			write(1, buf, i);
			i = 0;
			return ;
		}
		i++;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	bzero(&action, sizeof(struct sigaction));
	action.sa_sigaction = &signal_action;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
