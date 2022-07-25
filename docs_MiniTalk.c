Bism Ellah Elra7man Elra7eem 

#Pivoting to minitalk instead of pipex 

specs:
--------
1-executables : client server
2-Makefile
3-use libft
4-One global variable max + justification 
5-Create communication program bettween client and server
6-Server launch first and print it's PID
7-Client takes 2 parameters PID and string to send
./client PID "Hello world"
8-Send the string to the server
9-The server print it (it should print quickly I believe one char/time)
10-server can recieve several clients in a row without need to restart
11-Only allowed signal SIGUSR1 SIGUSR2
--------
Bonus:
1-Aknowledge recieving by sending back to the client
2-Unicode character support






Allowed functions:
-----------------
write
◦ ft_printf and any equivalent YOU coded ◦ signal
◦ sigemptyset
◦ sigaddset
◦ sigaction
◦ kill
◦ getpid
◦ malloc
◦ free
◦ pause
◦ sleep
◦ usleep
◦ exit


Implementation notes:
---------------------
1-Do the server let it print it's PID 
2-Do the client and check for the number of args 
3-Get your hands dirty with the Signals through the romanian guy video
4-Read about allowed functions
5-Voila make your project
