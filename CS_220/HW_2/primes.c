
#import <stdio.h>
#import <stdlib.h>

int minFact(int num);
int minLoop(int num);

int main(int argc,const char* argv[]){
        int first = atoi(argv[1]);
        if(first<=0){
                printf("first argument needs to be greater than 0 \n");
                exit(0);
        }
        int x = minFact(first);
        printf("The minimum factor is: \n");
        printf("%d \n",x);
        minLoop(first);
        return 0;   
}
int minFact(int num){
    for(int fact=2; fact<=num;fact++){
        if(num%fact==0) return fact;
    }
    return 0;
}
int minLoop(num){
  int num2 = num;
  int con = 1;
  printf("The factors of %d are: \n",num);
  while (con!=num){
    int y = minFact(num2);
    printf("%d \n",y);
    num2/=y;
    con *= y;
  }
  return 0;
}
                             
