#include "minitalk.h"
#include <time.h>

int binary;


int main()
{
	int		bit_counter;
	int		type_me;
	
	ft_printf("%d\n", getpid());
	bit_counter = 0;
	type_me = 0;
	while (1)
	{	
		pause();
		bit_counter = decoder(bit_counter, 7 - type_me);
		type_me++;
		if (type_me % 7 == 0)
		{
			ft_printf("char recieved <%c>", bit_counter);
			bit_counter = 0;
			type_me = 0;
		}
		
	}
}


void got_zero(int sig)
{
	binary = 0;
	ft_printf("recieving %d\n", binary);
	
	
}

void got_one(int sig)
{
	binary = 1;
	ft_printf("receiveing %d\n", binary);
}

int decoder(int bit_counter, int n)
{
		
	struct	sigaction sa1;
	struct	sigaction sa2;
	int		sig;
	
	sa1.sa_handler = &got_zero;
	sa2.sa_handler = &got_one;
	sigaction(SIGUSR1, &sa1, NULL);	
	sigaction(SIGUSR2, &sa2, NULL);
	ft_printf("bit_counter +=  power(2, %d) * %d;\n", n, binary);
	bit_counter +=  power(2, n) * binary;
	return (bit_counter);
}

int power(int base, int power)
{
	int	i;
	int result;

	result = base;
	i = -1;
	while (++i < power - 1)
		result *= base;
	if (power == 0)
		result = 1;
	ft_printf("testing power function: %d ** %d = %d\n", base, power, result);
	return (result);
}