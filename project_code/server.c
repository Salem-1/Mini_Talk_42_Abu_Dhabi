#include "minitalk.h"


int binary;

/*The binary message are sent in reverse order*/

int main()
{
	int		bit_counter;
	int		type_me;
	
	ft_printf("%d\n", getpid());
	bit_counter = 0;
	type_me = 0;
	while (1)
	{	
		//pause();
		bit_counter = decoder(bit_counter, type_me);
		type_me++;
		if (type_me % 8 == 0)
		{
			ft_printf(" <%c>\n", bit_counter);
			bit_counter = 0;
			type_me = 0;
		}
		
	}
}

void got_zero_or_one(int sig)
{
	if (sig == SIGUSR1)
	{
		binary = 0;
		ft_printf("%d ", binary);
	}
	else if (sig == SIGUSR2)
	{
		binary = 1;
		ft_printf("%d ", binary);
	}
	else
		ft_printf("Got wiered wrong message, I don't know what to do with it buddy\n");
	
}



int decoder(int bit_counter, int n)
{
		
	struct	sigaction sa;
	sa.sa_handler = &got_zero_or_one;
	sigaction(SIGUSR1, &sa, NULL);	
	sigaction(SIGUSR2, &sa, NULL);
	pause();
	bit_counter +=  power(2, n) * binary;
	//ft_printf("bit_counter +=  power(2, %d) * %d = %d;\n", n, binary, bit_counter);
	return (bit_counter);
}