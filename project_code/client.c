/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 07:57:45 by ahsalem           #+#    #+#             */
/*   Updated: 2022/07/27 07:57:45 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
SIGUSR1 -> 0
SIGUSR2 -> 1
Time for testing the workflow for minitalk, after this inshalla can submit
*/

int main(int argc, char **argv)
{
	int pid;

	if (argc < 3)
	{
		ft_printf("incorrect number of arguments\nclosing the program .......\n");
		return (1);
	}
	pid = atoi(argv[1]);
	encoder (argv[2], pid);
}

void encoder (char *argv,int pid)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		decimal_to_binary(argv[i], 1, pid);
		send_zero(7 - decimal_to_binary(argv[i], 0, pid), pid);
	}
	send_zero(8, pid);
}

int decimal_to_binary(int a, int flag, int pid)
{
	int	i;
	int	bin;
	int counter;

	i = -1;
	while (a > 0)
	{
		bin = a % 2;
		if (flag == 1)
			{
				if (bin == 0)
					kill(pid, SIGUSR1);

				else if (bin == 1)
					kill(pid, SIGUSR2);
				else
				{
					ft_printf("Error inside decimal to binary ,bin = %d which is not bin:(\n ", bin);
					return (1);
				}	
			}
			usleep(50);
		a /= 2;
		i++;
	}
	return (i);
}

void send_zero (int a, int pid)
{
	while (a > 0)
	{
		kill(pid, SIGUSR1);
		usleep(50);
		a--;
	}	
}
