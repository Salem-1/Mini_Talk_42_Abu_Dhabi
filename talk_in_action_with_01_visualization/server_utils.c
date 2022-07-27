#include "minitalk.h"


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
	//ft_printf("testing power function: %d ** %d = %d\n", base, power, result);
	return (result);
}