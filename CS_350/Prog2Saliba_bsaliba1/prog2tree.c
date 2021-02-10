#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void print_usage(){
	fprintf(stderr,"prog2tree [-u] [-N <num-levels>] [-M <num-children] [-p] [-s <sleep-time>]\n");
}

int main(int argc, char * argv[]) {	
	int num_levels = 1;
	int num_children = 3;
	int sleep_time = 1;
	bool pause_on = false;
	bool p_in = false;
	bool s_in = false;
	int level_index=0;//remember this is uninitialized
	if(argc!=0){
		for(int i=1;i<argc;i++){
			if(0==strncmp(argv[i],"-u",2)){
				print_usage();
				exit(0);
			}else if(0==strncmp(argv[i], "-s",2)){
				if(p_in == true){
					fprintf(stderr, "Cannot have both -p and -s flags as args\n");
					print_usage();
					exit(0);
				}else{
					s_in = true;
				}
			}else if(0==strncmp(argv[i],"-p",2)){
				if(s_in == true){
					fprintf(stderr, "Cannot have both -p and -s flags as args\n");
					print_usage();
					exit(0);
				}else{
					p_in = true;
				}
			}else if(0 ==strncmp(argv[i], "-N",2)){
				level_index = i+1;
			}
		}
		int option;
		while ((option = getopt (argc, argv, "N:M:s:p")) != -1){
			switch (option){
				case 'N':
					if(optarg[0]!='-'){
						if(atoi(optarg)<5){
							num_levels= atoi(optarg);
						}else{
							fprintf(stderr,"-N <num-levels>, num-levels cannot exceed 4\n");
							exit(0);
						}
					}else{
						fprintf (stderr, "Option -%c requires an argument.\n", optopt);
						print_usage();
						exit(0);
					}

					break;
				case 'M':
					if(optarg[0]!='-'){
						if(atoi(optarg)<4){
							num_children= atoi(optarg);
						}else{
							fprintf(stderr,"-M <num-children>, num-children cannot exceed 3\n");
						}
					}else{
						fprintf (stderr, "Option -%c requires an argument.\n", optopt);
						print_usage();
						exit(0);
					}
					break;
				case 'p':
					pause_on = true;
					break;	
				case 's':
					if(optarg[0]!='-'){
						sleep_time = atoi(optarg);
					}else{
						fprintf (stderr, "Option -%c requires an argument.\n", optopt);
						print_usage();
						exit(0);
					}
					break;					
				case '?':
					if (optopt == 'n' || optopt == 'M' ||
							optopt == 's' || optopt == 'm'){
						fprintf (stderr, "Option -%c requires an argument.\n", optopt);
						print_usage();
						exit(3);
					}else if (isprint (optopt)){
						fprintf (stderr, "Unknown option `-%c'.\n", optopt);
						print_usage();
						exit(4);

					}else{
						fprintf (stderr,
								"Unknown option character `\\x%x'.\n",
								optopt);
						print_usage();
						exit(5);
					}
				default:
					abort();
			}
		}
	}
       	if(level_index!=0){
		sprintf(argv[level_index],"%d",num_levels-1);//change num_levels in argv
	}
	if(num_levels==1){
		fprintf(stdout,"ALIVE: Level %d process with pid=%d, child of ppid=%d.\n",num_levels,getpid(),getppid());
		if(!pause_on){
			sleep(sleep_time);
		}else{
			pause();
		}
		fprintf(stdout,"EXITING: Level %d process with pid=%d, child of ppid=%d.\n",num_levels,getpid(),getppid());
		return 0;
	}
	fprintf(stdout,"ALIVE: Level %d process with pid=%d, child of ppid=%d.\n",num_levels,getpid(),getppid());
	const char* file_name = "./prog2tree";
	if(num_levels>1){
		pid_t pid= fork();
		if(pid==0){//child 1
			execvp(file_name,argv);	
		}
		else{//parent
			if(num_children >1){
				pid_t ppid2 = fork();
				if(ppid2==0){//child 2
					execvp(file_name,argv);
				}else{//parent
					if(num_children>2){
						pid_t ppid3 = fork();
						if(ppid3 ==0){//child 3
							execvp(file_name,argv);
						}
					}
				}
			}
		}
		for(int i =0; i<num_children;i++){
			wait(NULL);//wait for each child
		}
//		fprintf(stdout,"ALIVE: Level %d process with pid=%d, child of ppid=%d.\n",num_levels,getpid(),getppid());

	}else{

//		fprintf(stdout,"ALIVE: Level %d process with pid=%d, child of ppid=%d.\n",num_levels,getpid(),getppid());
//		if(!pause_on){
//			sleep(sleep_time);
//		}else{
//			pause();
//		}
//		fprintf(stdout,"EXITTING: Level %d process with pid=%d, child of ppid=%d.\n",num_levels,getpid(),getppid());
	}
	fprintf(stdout,"EXITING: Level %d process with pid=%d, child of ppid=%d.\n",num_levels,getpid(),getppid());

	return 0;
}
