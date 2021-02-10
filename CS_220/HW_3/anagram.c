#import <stdio.h>
#import <stdlib.h>
#import <string.h>
#import <ctype.h>

int main(int argc, char *argv[]){
   //getting the two string commandline arguments
   char first1[strlen(argv[1])];
   strcpy(first1,argv[1]);
   char second1[strlen(argv[2])];
   strcpy(second1, argv[2]);
    printf("%s %s \n",first1,second1);
   //remove all '_' from char[]
   char first2[strlen(argv[1])];
   char second2[strlen(argv[2])];
   int count=0;
   int spcnt=0;
   for(int i=0; i<strlen(first1);i++){
       if(first1[i]=='_'){
           spcnt++;
           continue;
       }else{
           first2[count]=first1[i];
           count++;
       }
    }
   int count2=0;
   int spcnt2=0;
    for(int i=0; i<strlen(second1);i++){
        if(second1[i]=='_'){
           continue;
           spcnt2++;
        }else{
            second2[count2]=second1[i];
            count2++;
        }
   }
    printf("%s %s \n", first2,second2);
   //Set correct length
   char first[strlen(first2)];
   strcpy(first,first2);
   first[strlen(first)-spcnt]=0;
   char second[strlen(second2)];
   strcpy(second,second2);
   second[strlen(second)-spcnt2]=0;
   printf("%s %s \n",first,second);
   //check if all chars are the same
   int check=0;
   for(int i=0;i<strlen(second);i++){
        second[i]=tolower(second[i]);
        for(int k=0;k<strlen(first);k++){
            first[k]=tolower(first[k]);
            if(second[i]==first[k]){
                check++;
                break;
            }
        }
    }
    if(check==strlen(first)){
        printf("%s is an anagram of %s \n",argv[1],argv[2]);
    }else{
        printf("%s is not an anagram of %s \n",argv[1],argv[2]);
    }
}

