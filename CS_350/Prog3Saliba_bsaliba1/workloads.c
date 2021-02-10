#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void printUsage(){
    fprintf(stderr, "./worloads <output_file> <seed> <option> //1 = NLoc, 2 = 80-20, 3 = Looping\n");
}
void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}
int main(int argc, char* argv[]){
    char* filename;
    int seed = time(0);
    int option;
    int arr[10000];
    FILE* myfile = stdout;
    if(argc==4){
        filename = argv[1];
        myfile = fopen(filename, "w");
        seed = atoi(argv[2]);
        option = atoi(argv[3]);
    }else{
        printUsage();
        exit(0);
    }
    srand(seed);
    switch(option){
        case 1://NO LOCALITY
            for(int i=0;i<10000;i++){
                fprintf(myfile,"%d\n",rand()%100);
            }
            break;
        case 2://80-20 Locality
            for(int i=0;i<8000;i++){
               arr[i] = rand()%20;
            }
            for(int i=8000;i<10000;i++){
                arr[i] = rand()%80+20;
            }
            shuffle(arr, 10000);
            for(int i=0;i<10000;i++){
                fprintf(myfile,"%d\n", arr[i]);
            }
            break;
        case 3://Looping Locality
            for(int i=0; i<10000/50; i++){
                for(int j=0;j<50;j++){
                    fprintf(myfile, "%d\n", j);
                }
            }
            break;
        default:
            fprintf(stderr, "No valid option chosen\n");
            exit(1);
    }
    return 0;
}
