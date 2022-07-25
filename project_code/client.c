#include "minitalk.h"


int main(int argc, char **argv)
{
	int pid;

	if (argc < 3)
	{
		ft_printf("incorrect number of arguments\nclosing the program .......\n");
		return (1);
	}
	pid = atoi(argv[1]);
	ft_printf("starting the program\n");
	ft_printf("process id recieved = %d\n", pid);
	ft_printf("string recieved:\n<%s>\n", argv[2]);
}
