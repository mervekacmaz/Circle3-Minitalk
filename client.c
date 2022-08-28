/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:10:55 by mkacmaz           #+#    #+#             */
/*   Updated: 2022/08/27 23:11:01 by mkacmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int		neg;
	long	num;
	int		i;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

void	send_message(char message, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((!!((message << i) & 128)) == 1)
			kill (pid, SIGUSR1);
		if ((!!((message << i) & 128)) == 0)
			kill (pid, SIGUSR2);
			i++;
		usleep(80);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		write (1, "You must give me at least 3 arguments", 40);
		return (0);
	}
	while (argv[2][i])
	{
		send_message(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
}
