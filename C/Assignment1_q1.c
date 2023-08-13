#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{ 
    
	int x = atoi(argv[1]);

	int frk = fork();
	if(frk < 0){
		exit(1);
	}
	else if(frk == 0){
	  		//printf("child process makes x = (%d)\n PID = %d\n", x, (int) getpid());
        printf("%d", x);
        while (x > 0 && x != 1){
            if ((x % 2) == 0){
                x = (x / 2); 
            }else{
                x = (3 * x + 1);
            }
            printf(",%d", x);
        }
	}
	else{
		int wai = wait(NULL);
		//printf("parent process makes x = (%d)\n PID = %d\n", x, (int) getpid());

	}
	return 0;
}