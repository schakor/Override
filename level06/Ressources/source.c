#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <stdlib.h>

int	auth(char *login, unsigned int serial) {

	int	i;
	int	key;
	int	len;


	login[strcspn(login, "\n")] = '\0';
	len = strnlen(login, 32);
	if (len <= 5)
		return (1);
	if (ptrace(0, 0, 1, 0) == -1) {
		puts("\033[32m.---------------------------.");
		puts("\033[31m| !! TAMPERING DETECTED !!  |");
		puts("\033[32m'---------------------------'");
		return (1);
	}
	key = (login[3] ^ 0x1337) + 0x5eeded;
	i = 0;
	while (i < len) {
		if (login[i] < ' ')
			return (1);	
		key = key - (login[i] ^ key);
		i++;
	}
	if (serial == key)
		return (0);
	return (1);
}

int			main(int ac, char **av) {
	unsigned int	serial;
	char		    login[32];
	int	        	ret;
	
	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(login, 32, stdin);
	
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", &serial);
	
	if (auth(login, serial))
		ret = 1;
	else
	{
		puts("Authenticated!");
		system("/bin/sh");
		ret = 0;
	}
	return (ret);
}
