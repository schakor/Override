#include <sys/types.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/prctl.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
    pid_t   child;
    int     wstatus;
    char    buff[156];

    child = fork();
    wstatus = 0;
    memset(buff, '\0', 156);
    if (child == 0)
    {
        prctl(1, 1);
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        puts("Give me some shellcode, k");
        gets(buff);
        return 0;
    }
    while(ptrace(3, child, 44, NULL) != 11)
    {
        wait(&wstatus);
        if (WIFEXITED(wstatus) || (WIFSIGNALED(wstatus) && WTERMSIG(wstatus)))
        {
            puts("child is exiting...");
            return 0;
        }
    }
    puts("no exec() for you");
    kill(child, 9);
    return 0;
}
