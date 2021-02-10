#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <getopt.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
void print_usage(){
    fprintf(stderr, "prog1sorter [-u] [-n <num-integers>] [-m <min-int>] [-M <max-int>] [-i <input-file-name>] [-o <output-file-name>] [-c <count-file-name>]\n");
}
int main(int argc, char* argv[], char* envp[]){
    clock_t begin = clock();    
    int arr[256]={0};
    int* p = (int*)malloc(sizeof(int)*1);
    int counter=0;
    int x = 0;

    int num_times= 100;
    int min_int=1;
    int max_int=255;
    FILE* cfile = stdout;
    char* cname = NULL;
    FILE* ifile = stdin;
    char* iname = NULL;
    FILE* ofile = stdout;
    char* oname= NULL;
    //parse cmd arguments here
    if(argc!=0){
        for(int i=1;i<argc;i++){
            if(0==strncmp(argv[i],"-u",2)){
                print_usage();
                exit(0);
            }
        }
        int option;
        while ((option = getopt (argc, argv, "n:m:M:o:i:c:")) != -1){
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
                         fprintf(stderr,"-m <min-int> must be at least 1\n");
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
              
              case 'o':
                  if(optarg[0]!='-'){
                        oname = optarg;
                  }else{
                        fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                        print_usage();
                        exit(0);
                  }
                  break;
              case 'i':
                  if(optarg[0]!='-'){
                        iname = optarg;
                  }else{
                        fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                        print_usage();
                        exit(0);
                  }
                  break;
              case 'c':
                  if(optarg[0]!='-'){
                        cname = optarg;
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
    }
    bool copen = false;
    if(iname!= NULL){
        ifile = fopen(iname,"r");
    }
    if(oname!= NULL){
        ofile = fopen(oname,"w");
    }
    if(cname!= NULL){
        cfile = fopen(cname,"w");
        copen=true;
    }
    int i=0;
    while(fscanf(ifile,"%d",&x)==1 && num_times>i){
        if(x>=min_int && x<=max_int){
            arr[x]++;
        }else{
            fprintf(stderr,"Value (%d) in input does not fall in the range of %i and %i\n",x, min_int, max_int);
            exit(6);
        }
        p[counter]=x;
        counter++;
        p = (int*)realloc(p,sizeof(int)*counter+1);
        i++;
    }
    //p = (int*)realloc(p,sizeof(int)*counter);
    qsort(p,counter,sizeof(int),cmpfunc);
    for(int i=0;i<counter;i++){
        fprintf(ofile,"%d\n",p[i]);
    } 
    //printf("%s\n",envp[7]);
    char* user = envp[7];
    //printf("%d",strlen(user));
    for(int i=5;i<strlen(user);i++){
        int ascii = (int)user[i];
        int num_times = arr[ascii];
        if(copen){
            fprintf(ofile,"%c\t%d\t\n",user[i],ascii);
            fprintf(cfile,"%d\n",num_times);
        }else{
            fprintf(ofile,"%c\t%d\t%d\n",user[i],ascii,num_times);
        }
    }
    clock_t end = clock();
    double clock_time = (double)(end-begin)/CLOCKS_PER_SEC;
    fprintf(stderr,"Program time: %f\n", clock_time);
}
