/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:11:10 by mkacmaz           #+#    #+#             */
/*   Updated: 2022/08/27 23:11:13 by mkacmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// get sigusr1 or sigusr2 signals 1 or 0 and put them inside a string
// get the value of the 8 bit string
// write the character with another function that converts bits to char

void	ft_itoa(pid_t pid)
{
	char	c;

	if (pid >= 10)
		ft_itoa(pid / 10);
	c = (pid % 10) + 48;
	write(1, &c, 1);
}

char	bits_to_char(char *str)
{
	int		i;
	int		num;
	char	c;

	i = 0;
	num = 0;
	while (i < 8)
	{
		num = num * 2 + (str[i] - 48);
		i++;
	}
	c = (char)num;
	return (c);
}

void	get_bits(int signum)
{
	static int	i = 0;
	char		str[8];
	char		m;

	if (signum == SIGUSR1)
	{
		str[i++] = '1';
	}
	else if (signum == SIGUSR2)
	{
		str[i++] = '0';
	}
	if (i == 8)
	{
		m = bits_to_char(str);
		write(1, &m, 1);
		i = 0;
	}
}

int	main(void)
{
	write (1, "Server Pid: ", 13);
	ft_itoa (getpid());
	write (1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, get_bits);
		signal (SIGUSR2, get_bits);
		pause();
	}
}
