#import <stdio.h>
#import <string.h>
#import <stdlib.h>

int strlength(char x[]); 
char *strcatm(char x[],char y[]);
int strlength2(char *x);
char *strcatp(char *x,char *y);

int main(int argc, char **argv){
    char retVal[128];
    strcpy(retVal,argv[1]);
    strcatm(retVal,argv[2]);
    printf("strcat matrix form yields: %s \n",retVal);
    char retVal2[128];
    strcpy(retVal2,argv[1]);
    strcatp(retVal2,argv[2]);
    printf("strcat pointer form yields: %s \n",retVal2);
}
//this is the function to concatenate two strings when given two char pointers
char *strcatp(char *x, char *y){
    char *address = x+strlength(x)-1;//this gets the mem address for where the first char in y should go
    for(int i=0;i<strlength(y);i++){
       *address = *(y+i);//sets the value at address to the value of the iTH char in the y char[]
       address++;
    }
    return x;
}
//this is the function to concatenate two strings when given two matrix inputs
char *strcatm(char x[],char y[]){
    int index = strlength(x) -1;//this gets the index for where the first char in y should go
    for(int i=0;i<strlength(y);i++){
       x[index+i]=y[i];
    }
   return x; 
}
//since we can't use any library functions i created my own strlen
int strlength(char x[]){
    int length=0;
    for(int i=0;i<127;i++){
        length++;
        if(x[i]==0x00){
            return length;
        }
    }
    return 0;
}
