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
/*	int num_levels = 1;
	int num_children = 3;
	int sleep_time = 1;
	bool pause_on = false;
	bool p_in = false;
	bool s_in = false;
	if(argc!=0){
		for(int i=1;i<argc;i++){
			if(0==strncmp(argv[i],"-u",2)){
				print_usage();
				exit(0);
			}else if(0==strncmp(argv[i], "-s",2)){
				if(p_in == true){
					fprintf(stderr, "Cannot have both -p and -s flags as args");
					print_usage();
					exit(0);
				}else{
					s_in = true;
				}
			}else if(0==strncmp(argv[i],"-p",2)){
				if(s_in == true){
					fprintf(stderr, "Cannot have both -p and -s flags as args");
					print_usage();
					exit(0);
				}else{
					p_in = true;
				}
			}
		}
		int option;
		while ((option = getopt (argc, argv, "N:M:ps:")) != -1){
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
							optopt == 's' || optopt =='o' || optopt == 'm'){
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
	}*/
	int num_levels = atoi(argv[1]);
	int num_children =3;
	char buffer[10];
	const char* file_name = "./simplefork";
	sprintf(buffer,"%d",num_levels-1);
//	printf("%s\n",buffer);
	if(num_levels>0){
		pid_t pid= fork();
		if(pid==0){//child 1
			printf("\n");
			execlp(file_name,buffer);	
		}
		else{//parent
			pid_t ppid2 = fork();
			if(ppid2==0){//child 2
				printf("\n");
				execlp(file_name,buffer);
			}else{//parent
				pid_t ppid3 = fork();
				if(ppid3 ==0){//child 3
					printf("\n");
					execlp(file_name,buffer);
				}else{
					for(int i =0; i<num_children;i++){
						wait(NULL);//wait for each child
					}
					fprintf(stdout,"ALIVE: Level %d process with pid=%d, child of ppid=%d.\n",3-num_levels,getpid(),getppid());
				}
			}
		}

	}else{
		fprintf(stdout,"ALIVE: Level %d process with pid=%d, child of ppid=%d.\n",3-num_levels,getpid(),getppid());
		//sleep here
	}
	return 0;
}
