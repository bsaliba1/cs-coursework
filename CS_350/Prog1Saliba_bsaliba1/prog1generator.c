#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <getopt.h>

void print_usage(){
    fprintf(stderr,"generator [-u] [-n <num-integers>] [-m <min-int>] [-M <max-int>] [-s <seed>] [-o <output-file-name>]\n");
}
int main(int argc, char* argv[]){
    clock_t begin = clock();
    int num_times= 100;
    int min_int=1;
    int max_int=255;
    FILE* myfile = stdout;
    char* filename = NULL;
    unsigned int seed = time(0);
    //parse cmd arguments here
    if(argc!=0){
        for(int i=1;i<argc;i++){
            if(0==strncmp(argv[i],"-u",2)){
                print_usage();
                exit(0);
            }
        }
        int option;
        while ((option = getopt (argc, argv, "n:m:M:s:o:")) != -1){
             switch (option){
              case 'n':
                  if(optarg[0]!='-'){
                      if(atoi(optarg)>0){
                          num_times= atoi(optarg);
                      }else{
                          fprintf(stderr,"-n <num-integers> num-integers must be at least 0");
                          exit(0);
                      }
                  }else{
                      fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                      print_usage();
                      exit(0);
                  } 
                  break;
              case 'm':
                  if(optarg[0]!='-'){
                     if(atoi(optarg)>=1){
                         min_int= atoi(optarg);
                     }else{
                         fprintf(stderr,"-m <min-int> must be at least 0");
                     }
                  }else{
                      fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                      print_usage();
                      exit(0);
                  }
                  break;
              case 'M':
                  if(optarg[0]!='-'){
                      if(atoi(optarg)<=1000000){
                          max_int = atoi(optarg);
                      }else{
                          fprintf(stderr,"-M <max-int> max-int must be at most 1000000");
                      }
                  }else{
                        fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                        print_usage();
                        exit(0);
                  }
                  break;
              case 's':
                  if(optarg[0]!='-'){
                       seed=atoi(optarg);
                  }else{
                        fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                        print_usage();
                        exit(0);
                  }
                  break;
              case 'o':
                  if(optarg[0]!='-'){
                        filename = optarg;
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
        
        if(min_int>max_int){
             fprintf(stderr,"Min int must be smaller than max int parameter\n");
             min_int =1;
             max_int =255;
         }
    }
    if(filename!= NULL){
        myfile = fopen(filename,"w");
    }
    srand(seed);
    for(int i=0;i<num_times;i++){
        fprintf(myfile,"%d\n",rand()%(max_int-min_int)+min_int);
    }
    clock_t end = clock();
    double time_spent = ((double) (end-begin))/CLOCKS_PER_SEC;
    fprintf(stderr,"Program time: %f\n",time_spent); 
}
