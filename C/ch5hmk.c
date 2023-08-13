#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

//tip - alt+6 = copy, ctrl+k = cut, ctrl+u = paste

int
main(int argc, char *argv[])
{
        int x = 100;

        //close(STDOUT_FILENO);
        //open("./ch5hmk.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
        int frk = fork();
        if(frk < 0){
                printf("this should not happen!!!!!!!\n");
        }
        else if(frk == 0){
                //x = 99;
               printf("child process PID = %d\n", (int) getpid());
        }
        else{
		/*
                char *myargs[3];
                myargs[0] = strdup("ls");
                myargs[1] = strdup("-l");
                myargs[2] = NULL;
                execvp(myargs[0], myargs);
		*/
		int childpid = (int)getpid() + 1;
		printf("%d\n", childpid);
		waitpid(childpid, NULL, 0);
		/* waitpid
		 * executes wait for the pid of the
		 * parent plus one (meaning the child),
		 * NULL meaning it's finished, and 0
		 * meaning it's equal to the child process
		*/
		printf("parent process PID = %d\n",(int)getpid());
                //int wai = wait(NULL);
                //x = 11;
                //printf("parent process makes x = (%d)\n PID = %d\n", x, (int) getpid());
        }
        return 0;
}
