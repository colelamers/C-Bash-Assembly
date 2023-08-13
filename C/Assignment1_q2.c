int
main(int argc, char *argv[])
{
    printf("\n%d", (int)getpid());

	int frk = fork();
	if(frk < 0){
		printf("this should not happen!!!!!!!\n");
	}
	else if(frk == 0){

	}
	else{
        printf("\n%d", (int)getpid());

		char *myargs[3];
		myargs[0] = strdup("ls");
		myargs[1] = strdup("-Fx");
		myargs[2] = NULL;
		execvp(myargs[0], myargs);
	}
	return 0;
}
