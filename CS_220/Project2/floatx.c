#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
typedef unsigned long floatx;

floatx doubleToFloatx(double in,int totBits,int expBits);
int getPlace(char array[]);
int getExpL(double in);
int getExpS(double in);
char *doubToArray(double frac);
floatx intToFloatx(int in, int bias);
int arrSize(char array[]);
double getFrac(double in,int exp);
int getBias(int expBits);
floatx doubToBits(double value);

int main(int argc, char **argv){
    if(argc<2){
        printf("To run program specify ./floatx <total_bits> <exponent bits>\n");
        return 1;
    }
    int totBits = atoi(argv[1]);
    int expBits = atoi(argv[2]);

    if((totBits<=2) && (totBits>=65)){
        printf("Total Number of bits must be greater than 2 and less than 65\n");
        return 1;
    }
    if((expBits<=0) && (expBits>(totBits-2))){
        printf("Exponent must be in range of 0<exp<=(total_bits - 2)\n");
        return 1;
    }
  
    while(!feof(stdin)) {
        double in=NAN; // NAN defined in math.h
        if(1==scanf("%lf ",&in)) {
             floatx fx = doubleToFloatx(in,totBits,expBits);
             printf("%14.8g = floatx(%d,%d) : %016lx\n",in,totBits,expBits,fx);
        } else {
             char buf[100];
             scanf("%s ",buf);
             printf("Input : %s not recognized as a double\n",buf);
        }
    }
}

floatx doubleToFloatx(double in, int totBits, int expBits){ 
   // Sign no longer necessary
    inn = fabs(in);
    int exp;
    if(inn<1){
        exp = getExpS(inn);
    }else{
        exp = getExpL(inn);
    }

    double frac = getFrac(inn,exp);
    floatx retVal = doubToBits(frac);

   //converting exp to bitwise long
    int bias = getBias(expBits); 
    exp = intToFloatx(exp,bias);
    exp = exp<<(totBits-1-expBits);
   
    //add sign bit
    if(in<0){
        retVal |= (1<<(totBits-1));
    }
    int x=0;
    for(int i=decPlace;i<(totBits-1-expBits+decPlace);i++){
        if(farr[i]==1){
            retVal^=(1<<x);
        }
        x++;
    }
    printf("retVal= %lu\n",retVal);
    retVal|=exp;
    
    return retVal;
}

//Get bias based on number of bits for exponent
int getBias(int expBits){
    if(expBits==2)return 1;
    else{
        int power = pow(2,expBits-2);
        return power+getBias(expBits-1);
    }
}
//Put Num into Array of Chars
//char *doubToArray(double frac){
//    char arr[200];
//    double num = frac;
//    sprintf(arr, "%2.13f", num);
//    int end=1;
//    int i=0;
//    while(end!=0x00){
//        i++;
//        end=arr[i];
//    }
//    return arr;
//}
//convert signed int to unsigned long with bias
floatx doubToBits(double value){
    union{
        double xi;
        floatx xo;
    }in;
    in.xi=value;
    return in.xo;
}
floatx intToFloatx(int in, int bias){
    int biased = in+bias;
    floatx retVal = (floatx)biased;
    return retVal;
}
//get Frac
double getFrac(double in,int exp){
    double frac = in/(pow(2,exp));
    return frac;
}
//Get Exponent if num larger than 2
int  getExpL(double in){
    if(in<2){
        return 0;
    }else{
        return 1+getExpL(in/2);
    }
}
//Get Exponent if num smaller than 1;
int getExpS(double in){
    if(in>=1){
        return 0;
    }else{
        return getExpS(in*2)-1;
    }
}
//gets the position of the decimal place
int getPlace(char array[]){
    int end =1;
    int place=0;
    int i=0;
    while(end!=0x00){
        if(array[i]=='.')place=i;
        i++;
        end=array[i];
        
    }
    return place;
}
//gets number of digits in number
int arrSize(char array[]){
    int size=0;
    for(int i=0;i<sizeof(*array);i++){
        if(array[i]==0x00)size=i;
    }
    return size;
}
    //Notes:
    //Able to decide sign bit
    //Got the range for denormal numbers
    //Able to get frac once we find 2's exponent
    //Able to put frac into char array that can be read
    //
    //Still Need to:
    //function to find decimal place
    //Make function to find 2's exponent
    //Chop off the numbers before decimal when putting into char array (should just start for loop two after starting point)
    //Convert 2's exponent into binary

