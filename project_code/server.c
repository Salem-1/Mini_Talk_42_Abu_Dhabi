#include "minitalk.h"


int main()
{
	int pid = getpid();
	if (pid == -1)
		return (1);
	//ft_putstr(ft_itoa(pid));
	ft_printf("pid = %d\n", pid);
}
