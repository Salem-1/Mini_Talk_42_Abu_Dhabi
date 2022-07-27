


#ifndef FT_MINITALK_H
# define FT_MINITALK_H

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <unistd.h>
#include <signal.h> 
#include <time.h>

// #include <stdio.h> //delete before submission

int power(int base, int power);
int decoder(int bit_counter, int n);
void encoder(char *argv, int pid);
void got_zero_or_one(int sig);

void send_zero (int a, int pid);
int decimal_to_binary(int a, int flag, int pid);
int	is_pow_two(int a);
#endif
