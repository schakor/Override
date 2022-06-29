#include <stdio.h>
#include <string.h>
#include <strings.h>

char a_user_name[256];

int verify_user_name() {
	puts("verifying username....");
	return (strncmp("dat_wil", a_user_name, 7));
}

int verify_user_pass(char *pass) {
	return (strncmp("admin", pass, 5));
}

int main(void) {
	int	ret;
	char	pass[64];

	bzero(&(pass[0]), 64);
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 256, (FILE *)stdin);
	if (verify_user_name())
	{
		puts("nope, incorrect username...\n");
		ret = 1;
	}
	else
	{
		puts("Enter Password: ");
		fgets(pass, 100, (FILE *)stdin);
		if (verify_user_pass(pass) >= 0)
		{
			puts("nope, incorrect password...\n");
			ret = 1;
		}
		ret = 0;
	}
	return (ret);
}
