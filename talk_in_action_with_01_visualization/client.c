#include "minitalk.h"

/*
SIGUSR1 -> 0
SIGUSR2 -> 1
Time for testing the workflow for minitalk, after this inshalla can submit
*/

int main(int argc, char **argv)
{
	//stress testing the encoder;

	
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

	ft_printf("inside encoder argv[2] = %s\n", &argv[2]);
	i = -1;
	while (argv[++i])
	//while ( ++i < 10)
	{
		//ft_printf("%d      ", i);
		decimal_to_binary(argv[i], 1, pid);
		send_zero(7 - decimal_to_binary(argv[i], 0, pid), pid);
		// decimal_to_binary(i, 1, pid);
		// send_zero(7 - decimal_to_binary(i, 0, pid), pid);
		ft_printf("   <%c>", argv[i]);
		ft_printf("\n");
	}
	send_zero(8, pid);
}

int decimal_to_binary(int a, int flag, int pid)
{
	int	i;
	int	bin;
	int counter;

	i = -1;
	//ft_printf("inside decimal to binary\n");
	//Search how to convert decimal to bin again
	while (a > 0)
	{
		bin = a % 2;
		if (flag == 1)
			{
				if (bin == 0)
				{
					kill(pid, SIGUSR1);
					ft_printf("0 ");

				}
				else if (bin == 1)
				{
					kill(pid, SIGUSR2);
					ft_printf("1 ");
				}
				else
				{
					ft_printf("Error inside decimal to binary ,bin = %d which is not bin:(\n ", bin);
					return (1);
				}	
			}
			usleep(200);
		a /= 2;
		i++;
	}
	//ft_printf("\n");
	//ft_printf("\ninside decimal_to_binary, sending zero %d\n", 8 - i);
	return (i);
}

void send_zero (int a, int pid)
{
	//ft_printf("inside send zero, sending 0 %d times\n", a);
	while (a > 0)
	{
		kill(pid, SIGUSR1);
		ft_printf("0 ");
		usleep(200);
		a--;
	}	
	ft_printf("|");
}
int	is_pow_two(int a)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (a == power(2, i))
			return (1);
	}
	return (0);
}
