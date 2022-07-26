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

/*Sending each char as 01 then null terminate it by sending 7 consective zeros*/
void encoder (char *argv,int pid)
{
	int	i;

	ft_printf("inside encoder argv[2] = %s\n", &argv[2]);
	i = -1;
	while (argv[++i])
	{		
		send_zero(7 - decimal_to_binary(argv[i], 0, pid), pid);
		decimal_to_binary(argv[i], 1, pid);
	}
	send_zero(7, pid);
}

int decimal_to_binary(int a, int flag, int pid)
{
	int	i;
	int	bin;
	int counter;

	i = -1;
	//ft_printf("inside decimal to binary\n");
	while (a > 0)
	{
		bin = a % 2;
		if (flag == 1)
			{
				if (bin == 0)
				{
					kill(pid, SIGUSR1);
					ft_printf("sending 0\n");
				}
				else if (bin == 1)
				{
					kill(pid, SIGUSR2);
					ft_printf("sending 1\n");
				}
				else
				{
					ft_printf("Error inside decimal to binary ,bin = %d which is not bin:(\n ", bin);
					return (1);
				}	
			}
			//	usleep(150);
		a /= 2;
		i++;
	}
	ft_printf("inside decimal_to_binary, sending zero %d\n", 7 - i);
	return (i);
}

void send_zero (int a, int pid)
{
	ft_printf("inside send zero, sending 0 %d times\n", a);
	while (a > 0)
	{
		kill(pid, SIGUSR1);
		ft_printf("sending 0\n");
		//usleep(150);
		a--;
	}	
}